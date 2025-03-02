import ROOT

file = ROOT.TFile("data.root", "READ")
tree = file.Get("TTree")

hist = ROOT.TH1D("hist", "Histogram of Normally Distributed Random Numbers", 50, -5, 5)

tree.Draw("x >> hist")

# Customize the histogram
hist.SetLineColor(ROOT.kBlack)  
hist.SetLineWidth(3)            
hist.SetFillColor(ROOT.kYellow)

# Customize background
ROOT.gStyle.SetOptStat(0) 
ROOT.gPad.SetFillColor(ROOT.kWhite) 

hist.GetXaxis().SetTitle("x values")
hist.GetYaxis().SetTitle("Frequency")

hist.Fit("gaus")

canvas = ROOT.TCanvas("canvas", "Histogram Canvas", 800, 600)
hist.Draw("HIST")
canvas.SaveAs("histogram.png")

file.Close()
print("Histogram plotted and saved as histogram.png")
