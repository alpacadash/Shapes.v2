#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Square
{
  double side;
};

struct Rectangle
{
  double length;
  double width;
};

struct Circle
{
  double radius;
};

struct Triangle
{
  double side;
};

struct Cube
{
  double side;
};

struct Box
{
  double length;
  double width;
  double height;
};

struct Cylinder
{
  double radius;
  double height;
};

struct Prism
{
  double side;
  double height;
};
void calcSquare(ofstream&, const Square&);
void calcRectangle(ofstream&, const Rectangle&);
void calcCircle(ofstream&, const Circle&);
void calcTriangle(ofstream&, const Triangle&);
void calcCube(ofstream&, const Cube&);
void calcBox(ofstream&, const Box&);
void calcCylinder(ofstream&, const Cylinder&);
void calcPrism(ofstream&, const Prism&);
Square tokensToSquare(vector<string>&);
Rectangle tokensToRectangle(vector<string>&);
Circle tokensToCircle(vector<string>&);
Triangle tokensToTriangle(vector<string>&);
Cube tokensToCube(vector<string>&);
Box tokensToBox(vector<string>&);
Cylinder tokensToCylinder(vector<string>&);
Prism tokensToPrism(vector<string>&);
vector<string> parseString(string);
vector<void*> bag(ifstream&, ofstream&, vector<int>&);
void deleteBag(vector<void*>&, vector<int>&);
void readBag(ofstream&, vector<void*>&, vector<int>&);

void calcSquare(ofstream& out, const Square& x)
{
  double side = x.side;
  double area = side*side;
  double perimeter = side*4;
  cout << "SQUARE side=" << side;
  out << "SQUARE side=" << side;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcRectangle(ofstream& out, const Rectangle& x)
{
  double length = x.length;
  double width = x.width;
  double area = length*width;
  double perimeter = length*2 + width*2;
  cout << "RECTANGLE length=" << length << " width=" << width;
  out << "RECTANGLE length=" << length << " width=" << width;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcCircle(ofstream& out, const Circle& x)
{
  double radius = x.radius;
  double area = M_PI*radius*radius;
  double perimeter = 2*M_PI*radius;
  cout << "CIRCLE radius=" << radius;
  out << "CIRCLE radius=" << radius;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcTriangle(ofstream& out, const Triangle& x)
{
  double side = x.side;
  double area = (sqrt(3)*side*side)/4;
  double perimeter = 3*side;
  cout << "TRIANGLE side=" << side;
  out << "TRIANGLE side=" << side;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcCube(ofstream& out, const Cube& x)
{
  double side = x.side;
  double area = side*side*6;
  double volume = side*side*side;
  cout << "CUBE side=" << side;
  out << "CUBE side=" << side;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcBox(ofstream& out, const Box& x)
{
  double length = x.length;
  double width = x.width;
  double height = x.height;
  double area = length*width*2 + width*height*2 + length*height*2;
  double volume = length*width*height;
  cout << "BOX side=" << length << " width=" << width << " height=" << height;
  out << "BOX side=" << length << " width=" << width << " height=" << height;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcCylinder(ofstream& out, const Cylinder& x)
{
  double radius = x.radius;
  double height = x.height;
  double area = M_PI*radius*radius*2 + height*2*M_PI*radius;
  double volume = M_PI*radius*radius*height;
  cout << "CYLINDER radius=" << radius << " height=" << height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

void calcPrism(ofstream& out, const Prism& x)
{
  double side = x.side;
  double height = x.height;
  double area = (sqrt(3)*side*side*2)/4 + 3*side*height;
  double volume = (sqrt(3)*side*side*height)/4;
  cout << "PRISM side=" << side << " height=" << height;
  out << "PRISM side=" << side << " height=" << height;
  cout.setf(ios::fixed);
  cout.precision(2);
  out.setf(ios::fixed);
  out.precision(2);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
  out.unsetf(ios::fixed);
  out.precision(6);
}

Square tokensToSquare(vector<string>& token)
{
  Square* square = new Square;
  if(token.size() >= 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    square->side = stod(token[1]);
  }
  if(token.size() == 1) square->side = 0;
  Square& rSquare = *square;
  return rSquare;
}

Rectangle tokensToRectangle(vector<string>& token)
{
  Rectangle* rectangle = new Rectangle;
  if(token.size() >= 3)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    try {double a = stod(token[2]);}
    catch (invalid_argument& e) {
        token[2] = "0";
    }
    rectangle->length = stod(token[1]);
    rectangle->width = stod(token[2]);
  }
  else if(token.size() == 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    rectangle->length = stod(token[1]);
    rectangle->width = 0;
  }
  if(token.size() == 1)
  {
    rectangle->length = 0;
    rectangle->width = 0;
  }
  Rectangle& rRectangle = *rectangle;
  return rRectangle;
}

Circle tokensToCircle(vector<string>& token)
{
  Circle* circle = new Circle;
  if(token.size() >= 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    circle->radius = stod(token[1]);
  }
  if(token.size() == 1) circle->radius = 0;
  Circle& rCircle = *circle;
  return rCircle;
}

Triangle tokensToTriangle(vector<string>& token)
{
  Triangle* triangle = new Triangle;
  if(token.size() >= 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    triangle->side = stod(token[1]);
  }
  if(token.size() == 1) triangle->side = 0;
  Triangle& rTriangle = *triangle;
  return rTriangle;
}

Cube tokensToCube(vector<string>& token)
{
  Cube* cube = new Cube;
  if(token.size() >= 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    cube->side = stod(token[1]);
  }
  if(token.size() == 1) cube->side = 0;
  Cube& rCube = *cube;
  return rCube;
}

Box tokensToBox(vector<string>& token)
{
  Box* box = new Box;
  if(token.size() >= 4)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    try {double a = stod(token[2]);}
    catch (invalid_argument& e) {
        token[2] = "0";
    }
    try {double a = stod(token[3]);}
    catch (invalid_argument& e) {
        token[3] = "0";
    }
    box->length = stod(token[1]);
    box->width = stod(token[2]);
    box->height = stod(token[3]);
  }
  if(token.size() == 3)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    try {double a = stod(token[2]);}
    catch (invalid_argument& e) {
        token[2] = "0";
    }
    box->length = stod(token[1]);
    box->width = stod(token[2]);
    box->height = 0;
  }
  if(token.size() == 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    box->length = stod(token[1]);
    box->width = 0;
    box->height = 0;
  }
  if(token.size() == 1)
  {
    box->length = 0;
    box->width = 0;
    box->height = 0;
  }
  Box& rBox = *box;
  return rBox;
}

Cylinder tokensToCylinder(vector<string>& token)
{
  Cylinder* cylinder = new Cylinder;
  if(token.size() >= 3)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    try {double a = stod(token[2]);}
    catch (invalid_argument& e) {
        token[2] = "0";
    }
    cylinder->radius = stod(token[1]);
    cylinder->height = stod(token[2]);
  }
  if(token.size() == 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    cylinder->radius = stod(token[1]);
    cylinder->height = 0;
  }
  if(token.size() == 1)
  {
    cylinder->radius = 0;
    cylinder->height = 0;
  }
  Cylinder& rCylinder = *cylinder;
  return rCylinder;
}

Prism tokensToPrism(vector<string>& token)
{
  Prism* prism = new Prism;
  if(token.size() >= 3)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    try {double a = stod(token[2]);}
    catch (invalid_argument& e) {
        token[2] = "0";
    }
    prism->side = stod(token[1]);
    prism->height = stod(token[2]);
  }
  if(token.size() == 2)
  {
    try {double a = stod(token[1]);}
    catch (invalid_argument& e) {
        token[1] = "0";
    }
    prism->side = stod(token[1]);
    prism->height = 0;
  }
  if(token.size() == 1)
  {
    prism->side = 0;
    prism->height = 0;
  }
  Prism& rPrism = *prism;
  return rPrism;
}

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

vector<void*> bag(ifstream& in, ofstream& out, vector<int>& bagType)
{
  string shape;
  vector<string> tokens;
  vector<void*> myBag;
  while(!in.eof())
  {
    getline(in,shape);
    if(shape.find_first_not_of(" ") != string::npos)
    {
      tokens = parseString(shape);
      if(tokens[0] == "SQUARE")
      {
        Square* square = new Square;
        *square = tokensToSquare(tokens);
        myBag.push_back(square);
        bagType.push_back(1);
      }
      else if(tokens[0] == "RECTANGLE")
      {
        Rectangle* rectangle = new Rectangle;
        *rectangle = tokensToRectangle(tokens);
        myBag.push_back(rectangle);
        bagType.push_back(2);
      }
      else if(tokens[0] == "CIRCLE")
      {
        Circle* circle = new Circle;
        *circle = tokensToCircle(tokens);
        myBag.push_back(circle);
        bagType.push_back(3);
      }
      else if(tokens[0] == "TRIANGLE")
      {
        Triangle* triangle = new Triangle;
        *triangle = tokensToTriangle(tokens);
        myBag.push_back(triangle);
        bagType.push_back(4);
      }
      else if(tokens[0] == "CUBE")
      {
        Cube* cube = new Cube;
        *cube = tokensToCube(tokens);
        myBag.push_back(cube);
        bagType.push_back(5);
      }
      else if(tokens[0] == "BOX")
      {
        Box* box = new Box;
        *box = tokensToBox(tokens);
        myBag.push_back(box);
        bagType.push_back(6);
      }
      else if(tokens[0] == "CYLINDER")
      {
        Cylinder* cylinder = new Cylinder;
        *cylinder = tokensToCylinder(tokens);
        myBag.push_back(cylinder);
        bagType.push_back(7);
      }
      else if(tokens[0] == "PRISM")
      {
        Prism* prism = new Prism;
        *prism = tokensToPrism(tokens);
        myBag.push_back(prism);
        bagType.push_back(8);
      }
      else if(shape.compare("EOF") == 0) break;
      else{ cout << tokens[0] << " invalid object" << endl; }
    }
  }
  return myBag;
}


void deleteBag(vector<void*>& myBag, vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      delete pSquare;
    }
    else if(myBagType[i] == 2)
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if(myBagType[i] == 3)
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      delete pCircle;
    }
    else if(myBagType[i] == 4)
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if(myBagType[i] == 5)
    {
      {
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        delete pCube;
      }
    }
    else if(myBagType[i] == 6)
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      delete pBox;
    }
    else if(myBagType[i] == 7)
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if(myBagType[i] == 8)
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}

void readBag(ofstream& out, vector<void*>& myBag, vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
      Square& rSquare = *pSquare;
      calcSquare(out, rSquare);
    }
    else if(myBagType[i] == 2)
    {
      Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
      Rectangle& rRectangle = *pRectangle;
      calcRectangle(out, rRectangle);
    }
    else if(myBagType[i] == 3)
    {
      Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
      Circle& rCircle = *pCircle;
      calcCircle(out, rCircle);
    }
    else if(myBagType[i] == 4)
    {
      Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
      Triangle& rTriangle = *pTriangle;
      calcTriangle(out, rTriangle);
    }
    else if(myBagType[i] == 5)
    {
      {
        Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
        Cube& rCube = *pCube;
        calcCube(out, rCube);
      }
    }
    else if(myBagType[i] == 6)
    {
      Box* pBox = reinterpret_cast<Box*>(myBag[i]);
      Box& rBox = *pBox;
      calcBox(out, rBox);
    }
    else if(myBagType[i] == 7)
    {
      Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
      Cylinder& rCylinder = *pCylinder;
      calcCylinder(out, rCylinder);
    }
    else if(myBagType[i] == 8)
    {
      Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
      Prism& rPrism = *pPrism;
      calcPrism(out, rPrism);
    }
  }
}

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";
  ifstream fin;
  ofstream fout;
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");
  vector<int> bagsType;
  vector<void*> bags = bag(fin,fout,bagsType);

  readBag(fout,bags,bagsType);
  deleteBag(bags,bagsType);
  fin.close();
  fout.close();
}
