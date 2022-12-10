/**
 * @file opengl.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 10/Dec/2022
 *
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class VertexManager
{
public:
private:
  vector<vector<float>> vertCoords;
  vector<vector<float>> colCoords;
  vector<vector<float>> normalCoords;
};