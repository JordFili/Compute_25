import ROOT
import numpy as np

N = 1000  

file = ROOT.TFile("data.root", "RECREATE")
tree = ROOT.TTree("TTree", "Random Number Tree")

x = np.zeros(1, dtype=float)

tree.Branch("x", x, "x/D")

rng = ROOT.TRandom3(0)  # Random generator with seed 0
for _ in range(N):
    x[0] = rng.Gaus(0, 1)
    tree.Fill()

tree.Write()
file.Close()

print("Data generated and saved to data.root")
