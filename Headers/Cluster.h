
#ifndef _____CLUSTER_H_____
#define _____CLUSTER_H_____
#include <string>
#include <vector>
#include "Enemy.h"
#include <random>

class Cluster : public Character
{
public:
	Cluster();
	Cluster(int q);
	Cluster(std::string n);
	Cluster(std::string n, int q);
	/*
	Cluster(Enemy e, int q);
	*/
	vector<Character*> characterGroup;
	int isAlive();
	int clusterSize;
	bool combatReady;
	int readyTimeLeft;
	std::string ptoString();
	void fromString(std::string in);

	int lastDirection = -1;

};
#endif