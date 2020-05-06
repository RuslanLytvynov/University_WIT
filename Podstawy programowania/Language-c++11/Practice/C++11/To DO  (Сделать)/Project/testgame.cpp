#include <fstream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main(){

        int h, w;
        cin >> h >> w;

        int n;
        cin >> n;

        vector <int> v;
        v.resize(w, 0);

        int x = 0, H, W, X, maxH = 0;

        for(int i = 0; i < n; i++){
                cin >> H >> W >> X;

                if(X == 1 && W == w){
                        cout << maxH << endl;
                        continue;
                }

                if(X+W-1 > w){
                        cout << "GAME OVER";
                        return 0;
                }

                for(int j = X-1; j < X+W-1; j++){
                        if(v[j] == 0){
                                x++;
                        }
                        v[j] += H;
                        if(v[j] > maxH){
                                maxH = v[j];
                        }
                }

                if(maxH > h){
                        cout << "GAME OVER";
                        return 0;
                }

                while(x == w){
                        maxH--;
                        for(int j = 0; j < w; j++){
                                v[j]--;
                                if(v[j] == 0){
                                        x--;
                                }
                        }
                }

                cout << maxH << endl;

        }


        return 0;
}
