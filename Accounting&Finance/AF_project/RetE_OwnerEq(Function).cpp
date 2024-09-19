void RetE_OwnerEq(int beginning){
	string line;
    ifstream infile;
    infile.open("Trial_balance.txt");
    string l2, l3, l4;
    while(!infile.eof()){

    getline(infile, line);
    stringstream ss(line);
    getline(ss, l2, ',');
    if(l2=="Dividends"){
    	
    getline(ss, l3, ',');
	int d;
	cout << " \t\t\t\tStatement of Retained Earnings" << endl<<endl;
   cout << " Beginning retained Earnings+Net Income:";
        for (int j = 0; j < 20; j++)
        {
            cout << " ";
        }
        cout << beginning << endl;
    
    
    cout <<"Less " <<l2;

    for (int j = 0; j < 35 - l2.length(); j++)
    {
        cout << " ";
    }

        getline(ss, l4);
        if (l4 != "")
        {
            int div = stoi(l4);
            d=div;
            for (int j = 0; j < 20; j++)
            {
                cout << " ";
            }
            cout <<"(" <<d<<")"<< endl;
        }  
    int ret_earnings=beginning - d;
	cout << " Ending retained Earnings:";
        for (int j = 0; j < 35; j++)
        {
            cout << " ";
        }
        cout << ret_earnings << endl;
		}
    else if(l2=="Capital"){
    	
    	getline(ss, l3, ',');
	int capital;
	cout << " \t\t\t\tStatement of Owner's Equity" << endl<<endl;
   cout << " Beginning Owner's Equity+Net Income:";
        for (int j = 0; j < 20; j++)
        {
            cout << " ";
        }
        cout << beginning << endl;
    
    
    cout <<l2;

    for (int j = 0; j < 35 - l2.length(); j++)
    {
        cout << " ";
    }

        getline(ss, l4);
        if (l4 != "")
        {
            int cap = stoi(l4);
            capital=cap;
            for (int j = 0; j < 23; j++)
            {
                cout << " ";
            }
            cout <<capital<< endl;
        }
        
    int owner_eq=beginning + capital;
    cout<<"Less Drawing ";
    for (int j = 0; j < 40; j++)
        {
            cout << " ";
        }
	cout<<"\t (0)";
	cout<<endl;
	cout << " Ending Owner's Equity:";
        for (int j = 0; j < 35; j++)
        {
            cout << " ";
        }
        cout << owner_eq << endl;
	}
	}
}
