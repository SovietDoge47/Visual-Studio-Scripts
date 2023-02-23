#include <stdio.h>
#include <stdlib.h>

//returns the file size in bytes
int getFileSize(char * filePath);

//copy genesis.txt and into genesis_copy.txt
void main()
{
   //char * is a shortcut to do the same thing as string
   char * path = "genesis.txt";
   char * newpath = "reversed_genesis.txt";
   FILE * inputStream, * outputStream;
   inputStream = fopen(path, "r"); //r, w, r+, w+, a, a+
   outputStream = fopen(newpath, "w");

   int fileSize = getFileSize(path);

   printf("the input file size is %d bytes.\n", fileSize);

   char * buf;
   char * outputBuf;
   buf = malloc(fileSize);
   outputBuf = malloc(fileSize);

   size_t bufLength = fileSize / sizeof(char);

   //fread(buf, fileSize, 1, inputStream); // Same thing as on line below (minus the if)
   if (fread(buf, 1, fileSize, inputStream) > 0)
   {
        for(int i=0; i < bufLength; i++)
        {
            outputBuf[i] = buf[bufLength-i-1];
        }
        fwrite(outputBuf, fileSize, 1, outputStream);
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