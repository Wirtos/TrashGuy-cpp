#ifndef TRASHGUY_H
#define TRASHGUY_H

#include <string>
#include <vector>
#include <stdio.h>

#include "utf8_tools.h"


class TrashGuy {
public:
    TrashGuy(const std::string &word,
             const std::string &sprite_can = "\xf0\x9f\x97\x91",
             const std::string &sprite_left = "<(^_^ <)",
             const std::string &sprite_right = "(> ^_^)>") {
        word_ = word;
        sprite_can_ = sprite_can;
        sprite_left_ = sprite_left;
        sprite_right_ = sprite_right;
    };

    std::vector<std::string> generate(FILE *file = NULL) {

        std::vector<std::string> vec = utf8_to_vector(word_);
        std::vector<std::string> res;
        std::string curletter;
        std::string cursprite;
        short action = 1;

        for (size_t i = 0, done = 0, max_x = vec.size(), rel_x = 2, x = 1; done < max_x;) {
            if (rel_x == x) {
                action = -1;
                curletter = vec[i];
                i++;
            } else if (x == 0) {
                action = 1;
                curletter.clear();
                rel_x++;
                done++;
            }

            if (x == 0) {
                cursprite = sprite_left_;
            } else if (x == rel_x) {
                cursprite = sprite_right_ + curletter;
            } else if (curletter.empty()) {
                cursprite = sprite_right_;
            } else {
                cursprite = curletter + sprite_left_;
            }

            std::string temp;
            temp += sprite_can_;
            temp += std::string(x, ' ');
            temp += cursprite;
            temp += std::string(rel_x - x, ' ');
            temp += utf8_substr(word_, i, max_x);
            res.push_back(temp);

            x += action;
        }
        return res;
    };

private:
    std::string word_;
    std::string sprite_can_, sprite_left_, sprite_right_;

};

#endif
