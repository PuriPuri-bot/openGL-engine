﻿#include "Texture.h"

Texture::Texture(std::string path)
{
	glGenTextures(1, &glTexture); // инициализация текстуры openGL
	glBindTexture(GL_TEXTURE_2D, glTexture); // указываем, что сейчас будем использовать данную текстуру

	// повторяем текстуру по оси x
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	// повторяем текстуру по оси y
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// настройка фильтрации текстур
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// загрузка изображения 
	image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_AUTO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	// создание Mipmap`ов
	glGenerateMipmap(GL_TEXTURE_2D);

	// освобождение памяти изображения
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}


