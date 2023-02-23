#include <stdio.h>
#include <stdlib.h>

//returns the file size in bytes
int getFileSize(char * filePath);

//copy genesis.txt and into genesis_copy.txt
void main()
{
   //char * is a shortcut to do the same thing as string
   char * path = "genesis.txt";
   char * newpath = "genesis_copy.txt";
   FILE * inputStream, * outputStream;
   inputStream = fopen(path, "r"); //r, w, r+, w+, a, a+
   outputStream = fopen(newpath, "w");

   int fileSize = getFileSize(path);

   printf("the input file size is %d bytes.", fileSize);

   char * buf;
   buf = malloc(fileSize);

   //fread(buf, fileSize, 1, inputStream); // Same thing as on line below (minus the if)
   if (fread(buf, 1, fileSize, inputStream) > 0){
      fwrite(buf, fileSize, 1, outputStream);
   }

   fclose(inputStream);
   fclose(outputStream);
   free(buf);
}

int getFileSize(char * filePath)
{
   FILE * stream;
   stream = fopen(filePath, "r");
   fseek(stream, 0, SEEK_END);
   int ret;
   ret = ftell(stream);
   fclose(stream);
   return ret;
}