#include "Triangle.h"
#include <GL/gl.h>

Triangle::Triangle( QOpenGLShaderProgram *program, QOpenGLTexture *texture,
                    int vertexAttr, int texCoordAttr, int texUniform ) :
    m_program( program ),
    m_texture( texture ),
    m_vertexAttr( vertexAttr ),
    m_texCoordAttr( texCoordAttr ),
    m_texUniform( texUniform )
{
    initVertices();
    initTexCoords();
}

void Triangle::initVertices()
{
    vertices.clear();
    vertices.resize( 9 );
    // 0
    vertices[0] = 0.0f;
    vertices[1] = 0.5f;
    vertices[2] = 0.0f;
    // 1
    vertices[3] = -0.5f;
    vertices[4] = -0.5f;
    vertices[5] = 0.0f;
    // 2
    vertices[6] = 0.5f;
    vertices[7] = -0.5f;
    vertices[8] = 0.0f;
}

void Triangle::initTexCoords()
{
    texCoords.clear();
    texCoords.resize( 6 );
    // 0
    texCoords[0] = 0.5f;
    texCoords[1] = 1.0f;
    // 1
    texCoords[2] = 0.0f;
    texCoords[3] = 0.0f;
    // 2
    texCoords[4] = 1.0f;
    texCoords[5] = 0.0f;
}

void Triangle::draw()
{
    m_texture->bind();

    m_program->setAttributeArray( m_vertexAttr, vertices.data(), 3 );
    m_program->setAttributeArray( m_texCoordAttr, texCoords.data(), 2 );
    m_program->setUniformValue( m_texUniform, 0 );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_texCoordAttr );

    glDrawArrays( GL_TRIANGLES, 0, 3 );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_texCoordAttr );
}
