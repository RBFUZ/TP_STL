#pragma once
#include <set>
#include <iostream>
#include <vector>

using namespace std;

struct S_Coord{
	double d_X;
	double d_Y;
};

class MySet{

public:
	MySet(void);
	void DisplaySet(set<S_Coord> ms);
	set<S_Coord> addValue(set<S_Coord> ms, int number);
	vector<vector<double>> distanceEucliAll(set < S_Coord> ms, vector<vector<double>> mvd);
	void distanceEucli(set<S_Coord> ms, int pointA, int pointB);
};

bool operator<(const S_Coord & s1, const S_Coord & s2);