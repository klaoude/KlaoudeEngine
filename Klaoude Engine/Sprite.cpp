#include "Sprite.h"
#include "Vertex.h"

#include <cstddef>

namespace KlaoudeEngine
{
	Sprite::Sprite()
	{
		m_vboID = 0;
	}

	Sprite::~Sprite()
	{
		if (m_vboID != 0)
			glDeleteBuffers(1, &m_vboID);
	}

	void Sprite::init(float x, float y, float width, float height, std::string texturePath)
	{
		m_x = x;
		m_y = y;
		m_witdh = width;
		m_height = height;

		m_texture = RessourceManager::getTexture(texturePath);

		if (m_vboID == 0)
			glGenBuffers(1, &m_vboID);

		Vertex vertexData[6];

		//First Triangle
		vertexData[0].setPosition(x + width, y + width);
		vertexData[0].setUV(1.0f, 1.0f);

		vertexData[1].setPosition(x, y + height);
		vertexData[1].setUV(0.0f, 1.0f);

		vertexData[2].setPosition(x, y);
		vertexData[2].setUV(0.0f, 0.0f);

		//Second Triangle
		vertexData[3].setPosition(x, y);
		vertexData[3].setUV(0.0f, 0.0f);

		vertexData[4].setPosition(x + width, y);
		vertexData[4].setUV(1.0f, 0.0f);

		vertexData[5].setPosition(x + width, y + height);
		vertexData[5].setUV(1.0f, 1.0f);

		for (int i = 0; i < 6; i++)
			vertexData[i].setColor(255, 255, 125, 255);

		vertexData[1].setColor(125, 125, 255, 255);

		vertexData[4].setColor(125, 255, 125, 255);

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Sprite::draw()
	{
		glBindTexture(GL_TEXTURE_2D, m_texture.id);

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		//pos attrib
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
		//color attrib
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		//UV Attrib
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}