#include <iostream>
#include <queue>
using namespace std;

struct crew
{
	int hi;
	int Si;
	int Ei;
};

struct guest
{
	int h;
	int t;
};

int main()
{
	crew *Crew;
	guest Guest;
	queue <guest> GuestLine;

	int H, C, Q;

	cin >> H >> C >> Q;

	Crew = new crew[C];

	cout << endl << "Crew Information..." << endl;

	for (int i = 0; i < C; i++)
		cin >> Crew[i].hi >> Crew[i].Si >> Crew[i].Ei;

	cout << endl << "Guest Information..." << endl << endl;

	for (int i = 0; i < Q; i++)
	{
		cin >> Guest.h >> Guest.t;
		GuestLine.push(Guest);
	}

	cout << "\nOutput...\n";

        while (!GuestLine.empty())
        {
            int count[5]={0,0,0,0,0};
            for (int i = 0; i < Q; i++)
            {
                for (int j = 0; j< C; j++)
                {
                    if (GuestLine.front().t>=Crew[j].Si&&GuestLine.front().t<=Crew[j].Ei)
                    {
                        count[i] = 1;
                    }
                }

                for (int j = 0; j< C; j++)
                {
                    if (count[i]==0&&j==C-1)
                    {
                        cout<<"YES"<<endl;
                        GuestLine.pop();
                    }

                    else if (count[i]>0)
                    {
                        if(GuestLine.front().t>=Crew[j].Si&&GuestLine.front().t<=Crew[j].Ei)
                        {
                            if(GuestLine.front().h>Crew[j].hi)
                            {
                                cout<<"YES"<<endl;
                                GuestLine.pop();
                            }
                            else
                            {
                                cout<<"NO"<<endl;
                                GuestLine.pop();
                            }
                        }

                    }
                }break;

            }
        }
}
