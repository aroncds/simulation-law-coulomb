#include "ManagerAsset.h"

std::map<const char*, std::string> ManagerAsset::_shaders;
std::map<const char*, GLuint> ManagerAsset::_textures;

std::string ManagerAsset::loadShader(const char* path){
	if (_shaders.find(path) == _shaders.end()){
		std::string content;
		std::ifstream file(path, std::ios::in);

		if (!file.is_open()){
			std::cout << "Arquivo nao encontrado" << std::endl;
		}

		std::string line = "";
		while (!file.eof()){
			std::getline(file, line);
			content.append(line + "\n");
		}

		file.close();
		ManagerAsset::_shaders[path] = content;
		return content;
	}
	return _shaders[path];
}

GLuint ManagerAsset::TextureLoad(const char * file_name, int width, int height)
{
	if (_textures.find(file_name) == _textures.end()){
		GLuint texture;
		unsigned char * data;
		FILE * file;

		file = fopen(file_name, "rb");
		if (file == NULL) std::cout << "Arquivo não encontrado!" << std::endl;

		data = (unsigned char*) malloc(width * height * 3);

		fread(data, width * height * 3, 1, file);
		

		glGenTextures(1, &texture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
		free(data);
		fclose(file);

		_textures[file_name] = texture;

		return texture;
	}
	return _textures[file_name];
}