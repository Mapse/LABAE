#include "TGraph.h"
#include  "TGraphErrors.h"
#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"

using namespace std;

void grafDecai(){
    
    // Criação do arquivo para guardar os histogramas.
    TFile *file = new TFile("decaimuon.root", "RECREATE");
    TTree *tree = new TTree("Tempos de decaímento do múon", "tempos de decaimento");

    auto n = tree->ReadFile("tempo_decaimento.txt", "t/D",' ');
    n += tree->ReadFile("tempo_decaimento2.txt", "t/D",' ');
    n += tree->ReadFile("tempo_decaimento3.txt", "t/D",' ');
    n += tree->ReadFile("tempo_decaimento4.txt", "t/D",' '); 

    Double_t t;

    tree->SetBranchAddress("t", &t);

    TH1D *hist = new TH1D("Tempo de decaimento","Tempo de decaimento", 100, 0., 25.);

    // Criação do canvas.
    TCanvas *c1 = new TCanvas("Plot", "Plots - tempo de vida médio", 700, 600);
    // Definindo escala logaritmica para o eixo y.
    c1->SetLogy();
    hist->GetXaxis()->SetTitle("#mus");
    hist->GetYaxis()->SetTitle("Entries.");

    for (unsigned i = 0; i !=n;i++){
        tree->GetEntry(i);
        if (t == 0) continue;
        hist->Fill(t/1000);
    }
    hist->Draw();
    cout << hist->GetStdDev() << endl;
    // O fit vai de 1,5 até 25 us: 2,1743574 us 
    // Tempo de ref: 2.1969811
    // Obter no parâmtro: 0.455

}


// Essa função pega o arquivo de saída de um QDC e monta a distribuição de cargas
// de um cintilador utilizado na prática de medida de vida média dos múons.
void cargaMu(){

    TFile *file = new TFile("Carga dos múons","RECREATE");
    TTree *tree = new TTree("Carga dos múons", "Carga dos múons");
    TTree *tree1 = new TTree("Carga do pedestal", "Carga do pedestal");

    auto n = tree->ReadFile("carga_muons.txt", "qc/D",' ');
    auto n1 = tree1->ReadFile("cargapedestal.txt", "qp/D",' ');
    cout << n << "aaaaaaa" << n1 << endl;

    TH1D *hist = new TH1D("Carga dos m#acute{u}ons","Carga dos m#acute{u}ons", 150, 0.1, 200);
    hist->GetXaxis()->SetTitle("fC");
    hist->GetYaxis()->SetTitle("Entries.");

    Double_t qc, qp;
    tree->SetBranchAddress("qc", &qc);
    tree1->SetBranchAddress("qp", &qp);

    for (unsigned i = 0;i !=n ; i++){
        tree->GetEntry(i);
        tree1->GetEntry(i);
        hist->Fill((qc-qp)*125/1000);
        cout << qc << endl;
    }
    TCanvas *c1 = new TCanvas("Plot", "Plots - tempo de vida médio", 700, 600);
    c1->cd();
    hist->Draw();
    
}


// Essa função pega o arquivo de saída de um QDC e monta a distribuição de cargas
// de um cintilador utilizado na prática de medida de vida média dos múons.
void cargaCint(){

    // Cria um arquivo para a saída dos dados.
    TFile *file = new TFile("carga_cintiladorA.root","RECREATE");
    // Cria uma tree para guardar o histograma de distribuição de carga.
    TTree *tree = new TTree("Carga dos múons", "Carga dos múons");
    
    // Insere os dados na tree através da leitura do arquivo em txt.
    auto n = tree->ReadFile("carga_muons.txt", "q/D",' ');
    
    // Cria um histograma para armazenar os dados.
    TH1D *hist = new TH1D("Carga do cintilador A","Carga do cintilador A", 150, 0.1, 200);
    
    // Define os títulos de cada eixo.
    hist->GetXaxis()->SetTitle("fC");
    hist->GetYaxis()->SetTitle("Entries.");

    // Criação de variável para utilizar no branch da tree.
    Double_t q;
    tree->SetBranchAddress("q", &q);

    for (unsigned i = 0;i !=n ; i++){
        tree->GetEntry(i);
        hist->Fill(q*125/1000); // Ao dividir por 1000 ainda se obtêm um resultado de fC.
        //cout << q << endl;
    }
    hist->Draw();
}