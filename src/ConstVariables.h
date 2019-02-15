#pragma once

unsigned const int WIDTH = 415;
unsigned const int HEIGHT = 640;

unsigned const int AmountOfBackgroundImages = 4;

const float RoadMinX = 12.0f;
const float RoadMaxX = 296.0f;

const int NumberOfLanes = 5;
const float RoadX[NumberOfLanes] = { RoadMinX,RoadMinX + 70 , RoadMinX + 140 , RoadMinX + 210,RoadMaxX };

const int AmountOfCarsTextures = 9;

const float EnemyStartY = -30.0f;
const float EnemyMaxY = 800.0f;

const float PlayerY = 500.0f;

const int FrameRate = 120;