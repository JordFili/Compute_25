import ROOT
import numpy as np

# Read data from HDECAY and FeynHiggs output files
hdecay_file = "hdecay_output.txt"
feynhiggs_file = "feynhiggs_output.txt"

masses = []
hdecay_widths = []
feynhiggs_widths = []

with open(hdecay_file, "r") as f:
    for line in f:
        data = line.split()
        if len(data) >= 2:
            try:
                masses.append(float(data[0]))
                hdecay_widths.append(float(data[1]))
            except ValueError:
                continue

with open(feynhiggs_file, "r") as f:
    for i, line in enumerate(f):
        data = line.split()
        if len(data) >= 2:
            try:
                feynhiggs_widths.append(float(data[1]))
            except ValueError:
                continue

# Convert to numpy arrays
masses = np.array(masses)
hdecay_widths = np.array(hdecay_widths)
feynhiggs_widths = np.array(feynhiggs_widths)
ratios = feynhiggs_widths / hdecay_widths  # Ratio plot

# Create graphs
graph_hdecay = ROOT.TGraph(len(masses), masses, hdecay_widths)
graph_feynhiggs = ROOT.TGraph(len(masses), masses, feynhiggs_widths)
graph_ratio = ROOT.TGraph(len(masses), masses, ratios)

graph_hdecay.SetLineColor(ROOT.kBlue)
graph_feynhiggs.SetLineColor(ROOT.kRed)
graph_hdecay.SetLineWidth(2)
graph_feynhiggs.SetLineWidth(2)

# Create canvas
canvas = ROOT.TCanvas("c1", "Higgs Width Comparison", 800, 800)
canvas.Divide(1, 2)

# Plot widths
canvas.cd(1)
graph_hdecay.SetTitle("Higgs Boson Widths;Higgs Mass (GeV);Width (GeV)")
graph_hdecay.Draw("AL")
graph_feynhiggs.Draw("L SAME")

# Plot ratio
canvas.cd(2)
graph_ratio.SetTitle("FeynHiggs/HDECAY Ratio;Higgs Mass (GeV);Ratio")
graph_ratio.SetLineColor(ROOT.kBlack)
graph_ratio.Draw("AL")

canvas.SaveAs("width_comparison.png")
