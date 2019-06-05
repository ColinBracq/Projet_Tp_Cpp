// Projet_Tp_Cpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
 
void ShowImage(const string nomFenetre,const Mat img)
{
	namedWindow(nomFenetre, WINDOW_NORMAL);
	imshow(nomFenetre, img);
}

int LoadImage()
{
	/*
	Création de l’objet image et lecture de l’image à partir du
	répertoire associé en utilisant la méthode imread()
	*/
	Mat image = imread("Q:/etudiants/Buffle.jpg");
	// Vérifier si l’image existe bien dans le répertoire
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	// Affichage de l’image dans une fenêtre (Image)
	string windowName = "Image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);

	return 0;
}

int ChangeBright()
{
	// Lecture de l’image avec la méthode imread ()
	Mat image = imread("Q:/etudiants/Buffle.jpg");
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	// Changement de luminosité dans l’image en utilisant la méthode convertTo()
	Mat imageBrighnessHigh100;
	String windowNameBrightnessHigh100 = "Buffle Divin";
	String windowNameBrightnessLow100 = "Buffle maléfique";
	image.convertTo(imageBrighnessHigh100, -1, 1, 100);
	Mat imageBrighnessLow100;
	image.convertTo(imageBrighnessLow100, -1, 1, -100);
	String windowNameOriginalImage = "Original Image";

	/*
	Affichage de l’image de l’image originale et des deux nouvelles
	images dans trois fenêtres différentes avec la méthode imshow ()
	*/
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, image);
	imshow(windowNameBrightnessHigh100, imageBrighnessHigh100);
	imshow(windowNameBrightnessLow100, imageBrighnessLow100);

	imwrite("Q:/etudiants/BuffleDivin.jpg", imageBrighnessHigh100);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

Mat Seuillage(const Mat image_ini)
{
	Mat image_fin;
	threshold(image_ini,image_fin, 127, 255, THRESH_BINARY);
	return image_fin;
}


int main(int argc, char** argv)
{
	Mat image = imread("Q:/etudiants/Buffle.jpg");
	Mat imagefin;
	imagefin = Seuillage(image);
	ShowImage("Normal", image);
	ShowImage("Seuillage", imagefin);
	waitKey(0);
}


