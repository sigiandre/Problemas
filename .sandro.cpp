//Sandro
//Códido para Visual Studio
//Crear archivos int62.txt y out62.txt

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace System;
using namespace std;

int main() {

	freopen("in62.txt", "r", stdin);
	freopen("out62.txt", "w", stdout);

	int n, m;
	int a, b;
	cin >> n >> m;
	vector<int> respuesta;
	queue<int> q;
	n = n + 1;
	int *incoming = new int[n];
	for (int i = 0; i < n; i++)
		incoming[i] = 0;
	vector<vector<int>> G(n);
	for (int i = 0; i < n; i++) {
		vector<int> aux;
		G.push_back(aux);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		incoming[b]++;
		G[a].push_back(b);
	}
	queue<int> aux;
	for (int i = 0; i < n; i++){
		if (incoming[i] == 0&&i!=0) {
			aux.push(i);
		}
	}
	q.push(aux.front());
	int t = aux.size();
	for (int i = 0; i < t; i++) {
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u != 0 && find(respuesta.begin(),respuesta.end(),u)==respuesta.end())
				respuesta.push_back(u);
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i];
				incoming[v]--;
				if (incoming[v] == 0) q.push(v);
			}
		}
		aux.pop();
		q = aux;
	}
	if (respuesta.size() == 0) cout << "Sandro fails.";
	else for (int i = 0; i < respuesta.size(); i++) {
		cout << respuesta[i] << "  ";
	}
	return 0;
}
