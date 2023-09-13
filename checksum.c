#include <stdio.h>

unsigned short check_sum(unsigned short *ip, int len)
{
    unsigned long sum = 0;
    unsigned short odd = 0;

    while (len > 1)
    {
        sum += *ip++;
        len -= 2;
    }

    if (len == 1)
    {
        *(unsigned char *)(&odd) = (*(unsigned char *)ip);
        sum += odd;
    }

    while (sum >> 16)
        sum = (sum >> 16) + (sum & 0xffff);

    return ~sum;
}

int main()
{
    unsigned short ip_data[] = {
        0x4500, 0x0028, 0x0000, 0x4000,
        0x0000, 0x3706, 0x1724, 0xDC11,
        0xAC1E, 0x014B};

    unsigned short checksum = check_sum(ip_data, sizeof(ip_data));
    printf("Checksum: %04X\n", checksum);

    return 0;
}