# include <iostream>
 
#define V 19
 
using namespace std;
 

int minimalnaUdaljenost(int udaljenost[], bool obradjeniVrh[])
{
    
    int min = 999999;
	int min_index;
	
 	int v = 0;
    while (v < V){  
        if (!obradjeniVrh[v] && udaljenost[v] <= min){
        	min = udaljenost[v];
			min_index = v;
		}
		v++;
	}
    return min_index;
}
 

void ispisiPut(int najkraci_put[], int j)
{
    
    if (najkraci_put[j]==-1)
        return;
        
    ispisiPut(najkraci_put, najkraci_put[j]);
 	cout << " " << j+1;
}
 

int ispisiRjesenje(int udaljenost[], int n, int najkraci_put[])
{
    int start = 0; 
    cout << "Vrh\t\tUdaljenost\tPut";
    for (int i = 0; i < V; i++) 
    {
    	cout << endl << start+1 << " -> " << i+1;
    	if(i+1 < 10) cout << " ";
    	cout << "\t\t" << udaljenost[i] << "\t\t" << start+1;

        ispisiPut(najkraci_put, i);
    }
    cout << endl;
}
 
 
void dijkstra(int graf[V][V], int start)
{
    int udaljenost[V];  
    
    bool obradjeniVrh[V];
 
    int najkraci_put[V];

    int i = 0;
    while (i < V) 
    {
        najkraci_put[0] = -1;
        udaljenost[i] = 999999;
        obradjeniVrh[i] = false;
        i++;
    }
 
    udaljenost[start] = 0;
 
    
    for (int brojac = 0; brojac < V; brojac++)
    {
        
        int u = minimalnaUdaljenost(udaljenost, obradjeniVrh);
 
        obradjeniVrh[u] = true;
         
        for (int v = 0; v < V; v++) {
            int udaljenostDoVrha =  udaljenost[u] + graf[u][v];
            if (!obradjeniVrh[v] && graf[u][v] && udaljenostDoVrha < udaljenost[v])
            {
                najkraci_put[v]  = u;
                udaljenost[v] = udaljenostDoVrha;
            }  
        }
    }

    ispisiRjesenje(udaljenost, V, najkraci_put);
}
 
int main(int argc, char** argv) {
   
    int graf[V][V] = { {0, 70, 0, 48, 0, 0, 0, 0, 49, 0, 0, 0, 0, 173, 0, 0, 0, 0, 0},
                        {70, 0, 41, 102, 0, 0, 0, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 41, 0, 0, 72, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {48, 102, 0, 0, 69, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0},
                        {0, 0, 72, 69, 0, 77, 113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 133, 77, 0, 69, 88, 0, 0, 0, 0, 0, 0, 0, 191, 0, 233, 280},
                        {0, 0, 163, 0, 113, 69, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 88, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 315},
                        {49, 115, 0, 0, 0, 0, 0, 0, 0, 82, 91, 0, 0, 133, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 82, 0, 26, 0, 0, 121, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 91, 26, 0, 79, 82, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 79, 0, 45, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 45, 0, 0, 0, 0, 0, 0, 0},
                        {173, 0, 0, 0, 0, 0, 0, 0, 133, 121, 0, 0, 0, 0, 26, 67, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 78, 119, 0, 0},
                        {0, 0, 0, 160, 0, 191, 0, 0, 0, 0, 0, 0, 0, 67, 78, 0, 73, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119, 73, 0, 58, 0},
                        {0, 0, 0, 0, 0, 233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58, 0, 113},
                        {0, 0, 0, 0, 0, 280, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 113, 0} };
 
    dijkstra(graf, 0);
 
    cin.get();
    return 0;
}
