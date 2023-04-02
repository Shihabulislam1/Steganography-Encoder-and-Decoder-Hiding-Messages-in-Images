# Steganography-Encoder-and-Decoder-Hiding-Messages-in-Images
This project is a steganography program that encodes secret messages into images and decodes them back. It's designed to be simple, efficient and easy to use.

#Overview:

This program is designed to encode and decode a message within a bitmap image file. The purpose of the program is to provide a means of hiding a message within an image in a way that is not easily detectable. This can be useful for various applications, such as sending confidential messages or for fun activities like puzzles and treasure hunts.

The intended use of the program is for anyone who needs to hide a message within an image file or decode a message that has been hidden in an image file using this program. The program can be used on any computer system that supports the C programming language, and the output files can be viewed on any system that supports bitmap image files or text files.

Functions:

2.1. encode_message

Description: The encode_message function takes two input parameters: the name of the image file and the name of the message file. The function reads the image file and the message file and encodes the message within the image file. The output is a new image file with the encoded message.

Input parameters:

    image_file: the name of the image file to be encoded
    message_file: the name of the message file to be encoded

Return values: None

Assumptions or constraints:

    The image file must be a bitmap image file.
    The message file must be a text file.
    The message file size must be less than or equal to the available space within the image file.
    The output file will have the name "encoded_image.bmp".

Pseudocode:
1. Open the image file.
2. Open the message file.
3. Create an output image file.
4. Copy the image file to the output file.
5. Get the size of the message file.
6. Append the message size to the output file.
7. Append the message to the output file.
8. Close all files.
Examples:
encode_message("image.bmp", "message.txt");
2.2. decode_message

Description: The decode_message function takes one input parameter: the name of the image file. The function reads the image file and decodes the message that has been previously encoded within it. The output is a new text file with the decoded message.

Input parameters:

    image_file: the name of the image file to be decoded

Return values: None

Assumptions or constraints:

    The image file must be a bitmap image file.
    The message must have been previously encoded within the image file using this program.
    The output file will have the name "decoded_message.txt".

Pseudocode:



1. Open the image file.
2. Get the size of the encoded message.
3. Create an output message file.
4. Copy the message to the output file.
5. Close all files.

Examples:
decode_message("encoded_image.bmp");

#Menu:

The menu allows the user to choose between two options:

    Encode Message
    Decode Message

Input Parameters:

    The user inputs a number from 1 to 2 to choose an option from the menu.
    If the user selects option 1 (Encode Message), they will be prompted to enter the name of the image file and the message file.
    If the user selects option 2 (Decode Message), they will be prompted to enter the name of the image file.

Return Values:

    The program returns a 0 upon successful execution.

#Assumptions or Constraints:

    The image file must be a .bmp file.
    The message file must be a .txt file.
    The message file size must be smaller than the remaining space in the image file.
    The encoded image file will be saved as "encoded_image.bmp" and the decoded message file will be saved as "decoded_message.txt".

#Pseudocode:

display_menu()
{
    print "1. Encode Message"
    print "2. Decode Message"
    print "Enter your choice: "
    read choice
    switch (choice) 
    {
        case 1:
            print "Enter the image file name: "
            read image_file
            print "Enter the message file name: "
            read message_file
            encode_message(image_file, message_file)
            break
        case 2:
            print "Enter the image file name: "
            read image_file
            decode_message(image_file)
            break
        default:
            print "Invalid choice!"
            break
    }
    return 0
}
Examples:
Example 1: Encoding a message
1. Encode Message
2. Decode Message
Enter your choice: 1
Enter the image file name: image.bmp
Enter the message file name: message.txt
The message has been successfully encoded!
Example 2: Decoding a message

1. Encode Message
2. Decode Message
Enter your choice: 2
Enter the image file name: encoded_image.bmp
The message has been successfully decoded!

#Limitations and Dependencies
#System Requirements

The program should work on any system that has a C compiler installed.
Dependencies

The program does not have any external dependencies.
Limitations or Known Issues

    The program can only encode and decode messages in text format.
    The size of the message should be smaller than the size of the image file, otherwise, the program will not work as expected.
    The program assumes that the input image file is in BMP format.
    The program does not currently support encryption or compression of the message.

#Conclusion

This program provides a simple way to encode a message into a BMP image file and decode it back. It can be useful in situations where you need to hide a message inside an image file without altering the appearance of the image. However, it has some limitations, such as the message size limitation and the lack of support for encryption and compression. Overall, the program is easy to use and can be a helpful tool for those who need to hide messages in images.
Final Thoughts and Recommendations

If you are planning to use this program for a sensitive message, we recommend you to consider additional encryption methods to ensure the security of your message. Additionally, we recommend testing the program with different image and message file sizes to ensure it meets your needs. Finally, we welcome any feedback or suggestions to improve the program's functionality.
















