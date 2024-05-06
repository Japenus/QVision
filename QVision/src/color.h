#ifndef COLOR_H
#define COLOR_H
#pragma once
#include<QColor>
#include<opencv.hpp>
using namespace cv;
const Scalar QVBlack(0,0,0);
const Scalar QVRed(0,0,255);
const Scalar QVBlue(255,0,0);
const Scalar QVGreen(0,255,0);
const Scalar QVCyan(255,255,0);
const Scalar QVYellow(0,255,255);
const Scalar QVPurple(255,0,255);
const Scalar QVPink(255,192,203);
const Scalar QVOrange(0,165,255);
const Scalar QVWhite(255,255,255);
using namespace QColorConstants;
using namespace QColorConstants::Svg;
#endif // COLOR_H
