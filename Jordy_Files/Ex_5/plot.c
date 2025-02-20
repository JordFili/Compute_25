void plot_data() {
    TFile* file = new TFile("data.root", "READ");
    TTree* tree = (TTree*)file->Get("TTree");

    TH1D* hist = new TH1D("hist", "Histogram of Normally Distributed Random Numbers", 50, -5, 5);
    
    tree->Draw("x >> hist");

    hist->SetLineColor(kBlack);   // Set the histogram line color to black
    hist->SetLineWidth(3);        // Set the line width to make it thicker
    hist->SetFillColor(kYellow);  // Set the fill color to yellow
    gStyle->SetOptStat(0);        // Disable the statistics box

    // Customize the canvas background
    gPad->SetFillColor(kWhite);  // Set the background color of the canvas to white

    hist->GetXaxis()->SetTitle("x values");
    hist->GetYaxis()->SetTitle("Frequency");

    hist->Draw("HIST");

    hist->Fit("gaus");

    file->Close();
}
