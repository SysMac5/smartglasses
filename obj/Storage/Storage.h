#ifndef STORAGE_H
#define STORAGE_H

#include <vector>

class Text;
class Image;

class Storage {
public:
    std::vector<Image> images;
    std::vector<Text> texts;
    
    Storage() = default;

    void add_image(Image* image);
    
    Text* get_text();
};

#endif
