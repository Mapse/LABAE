#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFitResult.h"
#include "TStyle.h"


// Função que plota os dados.
// Para ver os dados, acessar o arquivo Coincidencia.csv
void plotgraf(){
   // Tamanho do array de dados (O zero não é considerado duas vezes!)
   unsigned const n = 21;
   // Eixo com os tempos considerados.
   double dt[n] = {-100, -90, -80, -70, -60, -50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   // Dados com as contagens que coincidiram.
   double ct[n] = {0, 0, 0, 0, 0, 0, 0, 21, 50, 52, 68, 62, 62, 66, 55, 42, 2, 1, 1, 0, 0};

   // Criação do canvas.
   TCanvas *canv = new TCanvas("Plot", "Tec de coincid.", 700, 600);
   // Criação do gráfico
   TGraph *gr = new TGraph(n, dt, ct);
   // Estilo do marcador (cruz).
   gr->SetMarkerStyle(47);
   // Tamanho do marcador (1 é o default).
   gr->SetMarkerSize(1.2);
   // Cor do marcador (kVioleta=890).
   gr->SetMarkerColor(890);
   // Título do gráfico.
   gr->SetTitle("T#acute{e}cnica de coincid#hat{e}ncia; t (#etas); coincid#hat{e}ncias");

   // Função gaussiana para plotagem.
   TF1 *ga = new TF1("ga","gaus");
   // Variável para guardar o resultado do fit.
   TFitResultPtr fit = gr->Fit(ga,"S M");
   // Imprime o resultado do fit na tela.
   gStyle->SetOptFit(1111);
   fit->Print();
   gr->Draw("AP");
   canv->SaveAs("Técnica de coincidência.pdf");
}