#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;


bool check(int wolf, int goat, int cabbage, int boat) {

	if ((cabbage && goat && !boat) || (!cabbage && !goat && boat))
		return false;

	if ((wolf && goat && !boat) || (!wolf && !goat && boat))
		return false;

	return true;
}

bool isEdge(vector<int> g[], int x, int y) {

	for (auto it : g[x])
		if (it == y)
			return true;
	return false;

}

void makeEdge(vector<int> g[], int x, int y) {

	if (!isEdge(g, x, y)) {
		g[x].push_back(y);
		g[y].push_back(x);
	}

}

int makeNumber(int wolf, int goat, int cabbage, int boat) {

	return 8 * wolf + 4 * goat + 2 * cabbage + 1 * boat;
}

vector<int> bfs(vector<int> graph[]) {

	queue < int > q;
	vector<int> res;
	int dads[16], viz[16];
	fill(dads, dads + 16, 0);
	fill(viz, viz + 16, 0);

	dads[0] = -1;
	q.push(0);
	viz[0] = 1;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto it : graph[node]) {

            //create the road
			if(it == 15){

				dads[it] = node;
				int currentNode = 15;
				while (currentNode != -1) {
					res.push_back(currentNode);
					currentNode = dads[currentNode];
				}
				return res;
			}

			if (viz[it] == 0) {
				viz[it] = 1;
				dads[it] = node;
				q.push(it);
			}
		}
	}

	return{};
}

int main() {

	vector < int > graph[16];

    //create the graph
	for (int i = 0; i < 16; i++) {
		int wolf    = (i & (1 << 3)) ? 1 : 0;
		int goat    = (i & (1 << 2)) ? 1 : 0;
		int cabbage = (i & (1 << 1)) ? 1 : 0;
		int boat    = (i & (1 << 0)) ? 1 : 0;

		if (!check(wolf, goat, cabbage, boat))
			continue;

		if (boat == 0) {

			//just boat
			if (check(wolf, goat, cabbage, 1))
				makeEdge(graph, i, makeNumber(wolf, goat, cabbage, 1));

			//just wolf and boat
			if (wolf == 0 && check(1, goat, cabbage, 1))
				makeEdge(graph, i, makeNumber(1, goat, cabbage, 1));

			//just goat and boat
			if (goat == 0 && check(wolf, 1, cabbage, 1))
				makeEdge(graph, i, makeNumber(wolf, 1, cabbage, 1));

			//just cabbage and boat
			if (cabbage == 0 && check(wolf, goat, 1, 1))
				makeEdge(graph, i, makeNumber(wolf, goat, 1, 1));

		}
		else {

			//just boat
			if (check(wolf, goat, cabbage, 0))
				makeEdge(graph, i, makeNumber(wolf, goat, cabbage, 0));

			//just wolf and boat
			if (wolf == 1 && check(0, goat, cabbage, 0))
				makeEdge(graph, i, makeNumber(0, goat, cabbage, 0));

			//just goat and boat
			if (goat == 1 && check(wolf, 0, cabbage, 0))
				makeEdge(graph, i, makeNumber(wolf, 0, cabbage, 0));

			//just cabbage and boat
			if (cabbage == 1 && check(wolf, goat, 0, 0))
				makeEdge(graph, i, makeNumber(wolf, goat, 0, 0));

		}
	}

    // printing
	int nr = 0;
	for (auto it : bfs(graph)) {
		int wolf    = (it & (1 << 3)) ? 1 : 0;
		int goat    = (it & (1 << 2)) ? 1 : 0;
		int cabbage = (it & (1 << 1)) ? 1 : 0;
		int boat    = (it & (1 << 0)) ? 1 : 0;

		if (wolf) cout << "W";
		if (goat) cout << "G";
		if (cabbage) cout << "C";
		if (boat) cout << "B";
		cout << "||";
		if (!wolf) cout << "W";
		if (!goat) cout << "G";
		if (!cabbage) cout << "C";
		if (!boat) cout << "B";

		nr++; //just for printing the -->...
		if(nr!=8)
			cout << " --> ";
	}
	cout << endl;


	system("pause");
	return 0;
}
