#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to encode the message
void encode_message(const char *image_file, const char *message_file)
{
    //Open the image file
    FILE *img_file = fopen(image_file, "rb");
    if (img_file == NULL)
    {
        printf("Error: Unable to open image file!\n");
        return;
    }

    //Open the message file
    FILE *msg_file = fopen(message_file, "rb");
    if (msg_file == NULL)
    {
        printf("Error: Unable to open message file!\n");
        return;
    }

    //Create an output image file
    FILE *out_file = fopen("encoded_image.bmp", "wb");
    if (out_file == NULL)
    {
        printf("Error: Unable to create output file!\n");
        return;
    }

    //Copy the image file to the output file
    char ch;
    while (fread(&ch, 1, 1, img_file))
    {
        fwrite(&ch, 1, 1, out_file);
    }

    //Get the message file size
    fseek(msg_file, 0, SEEK_END);
    long msg_size = ftell(msg_file);
    rewind(msg_file);

    //Append the message size to the output file
    fwrite(&msg_size, sizeof(long), 1, out_file);

    //Append the message to the output file
    while (fread(&ch, 1, 1, msg_file))
    {
        fwrite(&ch, 1, 1, out_file);
    }

    //Close all the files
    fclose(img_file);
    fclose(msg_file);
    fclose(out_file);

    printf("The message has been successfully encoded!\n");
}

//Function to decode the message
void decode_message(const char *image_file)
{
    //Open the image file
    FILE *img_file = fopen(image_file, "rb");
    if (img_file == NULL)
    {
        printf("Error: Unable to open image file!\n");
        return;
    }

    //Get the message size
    long msg_size;
    fseek(img_file, -sizeof(long), SEEK_END);
    fread(&msg_size, sizeof(long), 1, img_file);
    rewind(img_file);

    //Create an output message file
    FILE *out_file = fopen("decoded_message.txt", "wb");
    if (out_file == NULL)
    {
        printf("Error: Unable to create output file!\n");
        return;
    }

    //Copy the message to the output file
    char ch;
    fseek(img_file, -msg_size - sizeof(long), SEEK_END);
    while (fread(&ch, 1, 1, img_file))
    {
        fwrite(&ch, 1, 1, out_file);
    }

    //Close all the files
    fclose(img_file);
    fclose(out_file);

    printf("The message has been successfully decoded!\n");
}

int main()
{
    int choice;

    //Menu
    printf("1. Encode Message\n");
    printf("2. Decode Message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            char image_file[100], message_file[100];

            //Input the image file name
            printf("Enter the image file name: ");
            scanf("%s", image_file);

            //Input the message file name
            printf("Enter the message file name: ");
            scanf("%s", message_file);

            encode_message(image_file, message_file);
            break;
        }
        case 2:
        {
            char image_file[100];

            //Input the image file name
            printf("Enter the image file name: ");
            scanf("%s", image_file);

            decode_message(image_file);
            break;
        }
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}