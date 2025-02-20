void generate_data() {
    const int N = 1000;
    
    TTree* tree = new TTree("TTree", "Random Number Tree");
    
    double x;
    
    tree->Branch("x", &x, "x/D");

    TRandom3 randGen(0);
    for (int i = 0; i < N; i++) 
    {
        x = randGen.Gaus(0, 1);
        tree->Fill();
    }
    
    TFile* file = new TFile("data.root", "RECREATE");
    tree->Write();
    file->Close();
}
