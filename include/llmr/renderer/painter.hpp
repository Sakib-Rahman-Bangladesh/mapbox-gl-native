#ifndef LLMR_RENDERER_PAINTER
#define LLMR_RENDERER_PAINTER

#include "shader-fill.hpp"
#include "shader-line.hpp"

namespace llmr {

class transform;
class tile;

class painter {
public:
    painter(class transform *tranform);

    void setup();
    void teardown();
    void viewport();


    void clear();
    void render(std::shared_ptr<tile> tile);

    void drawClippingMask();
    void switchShader(Shader *shader);

private:
    void setupShaders();
    void changeMatrix(std::shared_ptr<tile> tile);

public:

private:
    transform *transform;
    float matrix[16];

    Shader *currentShader;
    FillShader *fillShader;
    LineShader *lineShader;

    uint32_t tile_stencil_buffer;
    uint32_t tile_border_buffer;
};

}

#endif
