#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <vector>

class Triangle
{
public:
    Triangle( QOpenGLShaderProgram *program, QOpenGLTexture *texture,
              int vertexAttr, int texCoordAttr, int texUniform );
    void initVertices();
    void initTexCoords();

    void draw();

    std::vector<float> vertices;
    std::vector<float> texCoords;

private:
    QOpenGLShaderProgram *m_program;
    QOpenGLTexture *m_texture;
    int m_vertexAttr;
    int m_texCoordAttr;
    int m_texUniform;
};

#endif // TRIANGLE_H
