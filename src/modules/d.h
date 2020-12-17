#ifndef MODULE_D_H
#define MODULE_D_H

#include "utils/errors.h"

/**
\brief Loads a block of a RLE file into a string
 @param f_rle RLE file that will be saved in the string
 @param block_size Size of the block that is going to be loaded
 @param error Address to load error in case of unsuccess
 @returns String with the loaded contents
*/
char* load_rle (FILE* f_rle, int block_size, _modules_error* error);

/**
\brief Decompresses from the RLE format to the original one
 @param buffer String that contains a block of the RLE file
 @param block_size Size of the block that is going to be decompressed
 @param size_sequence Adress in which to load the size of the decompressed string
 @returns Decompressed string
*/
char* decompress_string (char* buffer, int block_size, int* size_sequence);

/**
\brief Decompresses file which was compressed with RLE's algorithm and saves it to disk
 @param path Pointer to the original/RLE file's path
 @returns Error status
*/
_modules_error rle_decompress(char ** path);


/**
\brief Decompresses file which was compressed with Shannon Fano's algorithm and saves it to disk
 @param path Pointer to the original/RLE file's path
 @returns Error status
*/
_modules_error shafa_decompress(char ** path);

/**
\brief struct of a btree to save the symbols codes
*/
typedef struct btree{
    int code;
    char symbol;
    struct btree *left,*right;
} BTree;
#endif //MODULE_D_H
