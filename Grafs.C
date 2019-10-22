#include "TGraph.h"
#include "TCanvas.h"
#include "TMultiGraph.h"

// Função para gerar o gráfico de tensão por número de contagens
void ger10mv(){
   // Número de medidas realizadas
   const unsigned n = 13;

   // Dados para as medidas com limiar de 10 mV.
   // Contagens.
   double c[n] = {10, 31, 84, 157, 233, 530, 1103, 2208, 3711, 5390, 7381, 9796, 12880};
   // Tensões.
   double v[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   // Criação do gráfico para as medidas com limiar de 10 mV.
   TGraph *g1 = new TGraph(n, v, c);
   // Criação do canvas.
   TCanvas *c1 = new TCanvas("Plot", "Plots - caracterizacao de cintiladores", 700, 600);
   // Definindo escala logaritmica para o eixo y.
   c1->SetLogy();
   // Linha para o plot do limiar de 10 mV com a cor azul.
   g1->SetLineColor(4);
   g1->SetTitle("Num. de contanges por tens#tilde{a}o para limiares diferentes;Tens#tilde{a}o (V); Log(cont.)");
   g1->Draw();

   
}

void ger20mv(){
   const unsigned n = 13;

   double c[n] = {1, 4, 17, 55, 115, 196, 345, 707, 1388, 2533, 3984, 5773, 7644};
   double v[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   TGraph *g1 = new TGraph(n, v, c);
   TCanvas *c1 = new TCanvas("Plot", "ploton", 700, 600);
   c1->SetLogy();
   // Linha com a cor vermelha.
   g1->SetLineColor(3);
   g1->SetTitle("Num. de contanges por tens#tilde{a}o para limiar de 10 mV;Tens#tilde{a}o (V); Log(cont.)");
   g1->Draw();
}

void ger30mv(){
   const unsigned n = 13;
   double c[n] = {0, 1, 4, 16, 55, 113, 188, 308, 601, 1227, 2291, 3586, 5255};
   double v[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   TGraph *g1 = new TGraph(n, v, c);
   TCanvas *c1 = new TCanvas("Plot", "ploton", 700, 600);
   c1->SetLogy();
   // Linha com a cor amarela.
   g1->SetLineColor(5);
   g1->SetTitle("Num. de contanges por tens#tilde{a}o para limiar de 10 mV;Tens#tilde{a}o (V); Log(cont.)");
   g1->Draw();
}

void todos(){
   
   // Número de medidas realizadas
   const unsigned n = 13;

   // Criação do canvas.
   TCanvas *cv1 = new TCanvas("Plot", "Plots - caracterizacao de cintiladores", 700, 600);
   // Definindo escala logaritmica para o eixo y.
   cv1->SetLogy();
   cv1->SetGridx();
   cv1->SetGridy();

   // Dados para as medidas com limiar de 10 mV.
   // Contagens.
   double c1[n] = {10, 31, 84, 157, 233, 530, 1103, 2208, 3711, 5390, 7381, 9796, 12880};
   // Tensões.
   double v1[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   // Criação do gráfico para as medidas com limiar de 10 mV.
   TGraph *g1 = new TGraph(n, v1, c1);
   // Linha para o plot do limiar de 10 mV com a cor azul.
   g1->SetLineColor(4);
   g1->SetName("gr1");
   g1->SetTitle("10 mV");
   g1->SetDrawOption("AP");
   g1->SetLineWidth(2);
   
   // Dados para as medidas com limiar de 20 mV.
   // Contagens.
   double c2[n] = {1, 4, 17, 55, 115, 196, 345, 707, 1388, 2533, 3984, 5773, 7644};
   double v2[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   TGraph *g2 = new TGraph(n, v2, c2);
   g2->SetLineColor(3);
   g2->SetName("gr2");
   g2->SetTitle("20 mV");
   g2->SetDrawOption("AP");
   g2->SetLineWidth(2);

   double c3[n] = {0, 1, 4, 16, 55, 113, 188, 308, 601, 1227, 2291, 3586, 5255};
   double v3[n] = {1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900};
   TGraph *g3 = new TGraph(n, v3, c3);
   g3->SetLineColor(5);
   g3->SetName("gr2");
   g3->SetTitle("20 mV");
   g3->SetDrawOption("AP");
   g3->SetLineWidth(2);

   TMultiGraph *mg = new TMultiGraph();
   mg->Add(g1); 
   mg->Add(g2);
   mg->Add(g3);

   mg->SetTitle("Num. de contagens por tens#tilde{a}o para limiares diferentes; Tens#tilde{a}o (V); Log(cont.)");
   mg->Draw("a");
   cv1->BuildLegend();
   cv1->SaveAs("Contagens por tensão.pdf");
}

// Função para plotar a 
void widthCont(){
   const unsigned n = 9;

   // Dados para as medidas com limiar de 10 mV.
   // Contagens.
   double cont[n] = {1222, 1210, 1246, 1197, 1235, 1206, 1261, 1218, 1213};
   // Largura do sinal em nano segundos
   double wid[n] = {100, 150, 200, 250, 300, 350, 400, 450, 500};
   TGraph *gr = new TGraph(n, wid, cont);
   TCanvas *cv1 = new TCanvas("Plot", "Plots - caracterizacao de cintiladores", 700, 600);
   // Definindo escala logaritmica para o eixo y.
   //cv1->SetLogy();
   cv1->SetGridx();
   cv1->SetGridy();
   gr->SetMarkerStyle(21); 
   gr->SetTitle("Num. de contagens por largura do sinal; t(#etas);Conts.");
   gr->Draw("AP");
   cv1->SaveAs("Contagens por tempo.pdf");

}

