#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>

using namespace std;

const int AMMO_MAG_ADDR = 0xTOFILL;
const int AMMO_MAX_ADDR = 0xTOFILL;


int main()
{

    HANDLE process_id;
    HANDLE com_port;

    LPINT ammo_mag = new int;
    LPINT ammo_max = new int;
    int PID = 0;
    int COM = 0;

    ZeroMemory(ammo_mag, sizeof(int));
    ZeroMemory(ammo_max, sizeof(int));

    cout << "Enter PID (Process ID): ";
    cin >> PID;

    cout << "Enter COM Port: ";
    cin >> COM;

    if (COM > 9 || COM < 1) { cout << "Invalid COM port, please use 1-9." << endl; return -1; }
    if (PID == 0 || !PID ) { cout << "Please specify a valid process ID." << endl; return -1; }


    string port;
    switch(COM)
    {
        case 1:
            port = "COM1";
            break;
        case 2:
            port = "COM2";
            break;
        case 3:
            port = "COM3";
            break;
        case 4:
            port = "COM4";
            break;
        case 5:
            port = "COM5";
            break;
        case 6:
            port = "COM6";
            break;
        case 7:
            port = "COM7";
            break;
        case 8:
            port = "COM8";
            break;
        case 9:
            port = "COM9";
            break;
        default:
            cout << "Something has gone horribly wrong." << endl;
            return -1;
    }

    if ((com_port = CreateFile(port.c_str(), GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0)) == INVALID_HANDLE_VALUE)
    {
        cout << "Could not open " << port << endl;
        return -1;
    }
        cout << port << " opened." << endl;


    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
    if (!GetCommState(com_port, &dcbSerialParams))
    {
        cout << "Error getting COM port state." << endl;
        return -1;
    }
    cout << "Using 9600 baud, 8 data bits, 1 stop bit, no parity." << endl;
    cout << "Made by Jesse van Vliet (01/01/2016)." << endl;
    dcbSerialParams.BaudRate=CBR_9600;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    if(!SetCommState(com_port, &dcbSerialParams))
    {
        cout << "Error setting COM port state." << endl;
        return -1;
    }

    BYTE ENQ = 0x05;
    BYTE ACK = 0x06;
    bool arduino_detected = false;
    BYTE recv_buffer = 0x00;
    DWORD bytes;
    LPBYTE arduino_byte = &ENQ;
    LPBYTE arduino_recv = &recv_buffer;
    LPDWORD bytes_written = &bytes;
    COMMTIMEOUTS timeouts;

    timeouts.ReadIntervalTimeout = 100;
    timeouts.ReadTotalTimeoutMultiplier = 1;
    timeouts.ReadTotalTimeoutConstant = 150;
    timeouts.WriteTotalTimeoutMultiplier = 100;
    timeouts.WriteTotalTimeoutConstant = 100;
    SetCommTimeouts(com_port, &timeouts);

    WriteFile(com_port, arduino_byte, sizeof(arduino_byte), bytes_written, NULL);
    *bytes_written = 0;

    ReadFile(com_port, arduino_recv, sizeof(BYTE), bytes_written, NULL);
    if(recv_buffer == ACK)
    {
        cout << "Arduino found." << endl;
        bool arduino_detected = true;
    }
    else
    {
        for (short i = 0; i <= 3; i++) 
        {
            Sleep(500); 
            *bytes_written = 0;
            ReadFile(com_port, arduino_recv, sizeof(BYTE), bytes_written, NULL);
            if(recv_buffer == ACK)
            {
                cout << "Arduino found." << endl;
                bool arduino_detected = true;
                break;
            }
        }
    }


    if ((process_id = OpenProcess(PROCESS_VM_READ, false, PID)))
    {
        cout << "Process Opened." << endl;

        while (true)
        {
            Sleep(100); 
            bool result = false;
            result = ReadProcessMemory(process_id, (void*)AMMO_MAG_ADDR, ammo_mag, sizeof(int), NULL);
            if (!result)
            {
                cout << "Memory Read Failed." << endl;
                return 0;
            }

            result = ReadProcessMemory(process_id, (void*)AMMO_MAX_ADDR, ammo_max, sizeof(int), NULL);
            if (!result)
            {
                cout << "Memory Read Failed." << endl;
                return 0;
            }

            cout << "Ammo: " << *ammo_mag << "/" << *ammo_max << endl;

            char buffer[20];
            sprintf(buffer, "%d/%d", *ammo_mag, *ammo_max);
            WriteFile(com_port, &buffer, sizeof(buffer), bytes_written, NULL);
        }
    }
    else
    {
        cout << "Could not open process, check PID." << endl;
        return 0;
    }


    return 0;
}
