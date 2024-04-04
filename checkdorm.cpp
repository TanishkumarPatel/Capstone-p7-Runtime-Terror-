 string checkdorm(int chid)
  { 
    for (int j=0;j<musicid.size();j++)
    {
        if (stoi(musicid[j])==chid)
        {
            return dormname[j];
        }
    }
  }