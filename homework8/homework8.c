/*****************************************************************
//
//  NAME:        River Matsumoto 
//
//  HOMEWORK:    8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 13, 2022
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//      TCP Header response program. Creates a response when given a request.
//
//  REFERENCES:
//      https://www.programiz.com/c-programming/bitwise-operators
//      C textbook
//      Previous homeworks
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int readfile(const char[], unsigned char[]);
int writefile(const char[], const unsigned char[]);
void printheader(const unsigned char[]);
void makeheader(const unsigned char[], unsigned char[]);
void test();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION: Reads the TCP request headers and writes to a response file.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : successfully executed
//                 -1 : Error occurred
//
****************************************************************/
int main(int argc, char* argv[])
{
    int result;
    unsigned char header[20];
    unsigned char response_header[20];

    result = readfile("request1.bin", header);
    if (result == 1)
    {
        printf("Successfully read request1 header.\n");
        printheader(header);
        makeheader(header, response_header);
        result = writefile("response1.bin", response_header);
        if (result == 1)
        {
            printf("Successfully created response1 header.\n");
        }
        printheader(response_header);
    }

    result = readfile("request2.bin", header);
    if (result == 1)
    {
        printf("Successfully read request2 header.\n");
        printheader(header);
        makeheader(header, response_header);
        result = writefile("response2.bin", response_header);
        if (result == 1)
        {
            printf("Successfully created response2 header.\n");
        }
        printheader(response_header);
    }

    result = readfile("request3.bin", header);
    if (result == 1)
    {
        printf("Successfully read request3 header.\n");
        printheader(header);
        makeheader(header, response_header);
        result = writefile("response3.bin", response_header);
        if (result == 1)
        {
            printf("Successfully created response3 header.\n");
        }
        printheader(response_header);
    }

    return 0;
}


/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION: Reads the TCP request from a binary file and stores it in a char array.
//
//  Parameters:    filename (const char[]): The filename to read from.
//                  header (unsigned char[]): The array to store the header data into.
//
//  Return values:  0 : successfully read and stored data.
//                 -1 : Error occurred while reading the file.
//
****************************************************************/
int readfile(const char filename[], unsigned char header[])
{
    FILE* file;
    size_t num_read;
    int result;

    file = fopen(filename, "rb");
    if (file != NULL)
    {
        num_read = fread(header, sizeof(char), 20, file);
        if (num_read == 20)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }

        fclose(file);
    }
    else
    {
        result = 0;
    }

    return result;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION: Writes the TCP response to a binary file.
//
//  Parameters:    filename (const char[]): The filename to write to.
//                  response_header (const unsigned char[]): The response to write to the file
//
//  Return values:  0 : successfully wrote binary data to file.
//                 -1 : Error occurred while writing to the file.
//
****************************************************************/
int writefile(const char filename[], const unsigned char response_header[])
{
    FILE* file;
    int result, num_wrote;

    file = fopen(filename, "wb");
    if (file != NULL)
    {
        num_wrote = fwrite(response_header, sizeof(unsigned char), 20, file);
        if (num_wrote == 20)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }

        fclose(file);
    }
    else
    {
        result = 0;
    }

    return result;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION: Prints the header data of either a request or response in
//              a readable format.
//
//  Parameters:  header (const unsigned char[]): The data to parse and print.
//
//  Return values:  none
//
****************************************************************/
void printheader(const unsigned char header[])
{
    int source_port = 0;
    int dest_port = 0;
    unsigned int sequence_num = 0;
    unsigned int acknowledgement_num = 0;
    unsigned char control_bits = 0;
    int i;

    printf("Header: ");
    for (i = 0; i < 20; i++)
    {
        printf("%X ", header[i]);
    }
    printf("\n");

    source_port |= header[0];
    source_port |= header[1] << 8;
    printf("Source Port: %d\n", source_port);

    dest_port |= header[2];
    dest_port |= header[3] << 8;
    printf("Destination Port: %d\n", dest_port);
    printf("Destination Port char 1: %u\n", header[2]);
    printf("Destination Port char 2: %u\n", header[3]);

    sequence_num |= header[4];
    sequence_num |= header[5] << 8;
    sequence_num |= header[6] << 16;
    sequence_num |= header[7] << 24;
    printf("Sequence Number: %u\n", sequence_num);

    acknowledgement_num |= header[8];
    acknowledgement_num |= header[9] << 8;
    acknowledgement_num |= header[10] << 16;
    acknowledgement_num |= header[11] << 24;
    printf("Acknowledgement Number: %u\n", acknowledgement_num);

    control_bits = header[13];
    printf("Control bits that are set to 1:\n");
    if (((control_bits >> 0) & 1) == 1)
    {
        printf("FIN\n");
    }
    if (((control_bits >> 1) & 1) == 1)
    {
        printf("SYN\n");
    }
    if (((control_bits >> 2) & 1) == 1)
    {
        printf("RST\n");
    }
    if (((control_bits >> 3) & 1) == 1)
    {
        printf("PSH\n");
    }
    if (((control_bits >> 4) & 1) == 1)
    {
        printf("ACK\n");
    }
    if (((control_bits >> 5) & 1) == 1)
    {
        printf("URG\n");
    }
    printf("\n");
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION: Reads from a TCP request and creates a response header
//
//  Parameters:  header (const unsigned char[]): The request header to create a response from.
//              response_header (unsigned char[]): The array to store the response.
//
//  Return values:  none
//
****************************************************************/
void makeheader(const unsigned char header[], unsigned char response_header[])
{
    unsigned int source_port = 0;
    unsigned int sequence_num = 0;
    unsigned char control_bits = 0;
    int i;

    /* change the response header later */
    for (i = 0; i < 20; i++)
    {
        response_header[i] = header[i];
    }

    /* swap source port and dest port*/
    response_header[0] = header[2];
    response_header[1] = header[3];
    response_header[2] = header[0];
    response_header[3] = header[1];

    source_port |= header[0];
    source_port |= header[1] << 8;
    if ((source_port >> 15) == 1)
    {
        source_port ^= 0x440; /*0000 0100 0100 0000*/
        response_header[2] = (unsigned char) (source_port & 0xFF); /* 1111 1111*/
        response_header[3] = (unsigned char) (source_port >> 8);
    }

    /* acknowledgement number = sequence number*/
    for (i = 8; i < 12; i++)
    {
        response_header[i] = header[i - 4];
    }

    /* increment sequence number by 1 */
    for (i = 7; i >= 4; i--)
    {
        sequence_num <<= 8;
        sequence_num |= header[i];
    }
    sequence_num++;
    /* Slice the 4 byte integer up into characters using bit shift and AND operator */
    response_header[4] = (unsigned char) sequence_num & 0xFF; /* 1111 1111 one byte */
    response_header[5] = (unsigned char) (sequence_num >> 8) & 0xFF;
    response_header[6] = (unsigned char) (sequence_num >> 16) & 0xFF;
    response_header[7] = (unsigned char) (sequence_num >> 24) & 0xFF;

    /* If SYN, then ACK and SYN must be true */
    control_bits = header[13];
    if (((control_bits >> 1) & 1) == 1)
    {
        /* both ACK and SYN must be set */
        response_header[13] |= 0x10; /* 0001 0000*/
    }
}
