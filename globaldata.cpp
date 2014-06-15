#include "globalSettings.h"
#include "globaldata.h"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> gd_vAnt;
std::vector<float> gd_vFer;


globalData::globalData()
{
}

void globalData::print(char what, bool writeCycles)
{
    if(what=='a')
    {
        std::cout << "\nPrinting standalone ants in cycle..." << std::endl;
        for(unsigned int i=1; i<gd_vAnt.size(); i++)
        {
            if(writeCycles)
                std::cout << "Cycle " << i << ":\t" << gd_vAnt.at(i) << '\n';
            else
                std::cout << gd_vAnt.at(i) << '\n';
        }

        std::cout << '\n';
    }

    if(what=='s')  // Ants summed with previous records
    {
        std::cout << "\nPrinting summed ants in cycle..." << std::endl;
        int val;
        for(unsigned int i=1; i<gd_vAnt.size(); i++)
        {
            val=0;
            for(int j=i; j>=0;j--)
                val+=gd_vAnt.at(j);

            if(writeCycles)
                std::cout << "Cycle " << i << ":\t" << val << std::endl;
            else
                std::cout << val << std::endl;
        }
    }

    if(what=='f')
    {
        std::cout << "\nPrinting feromons table...";
        if(writeCycles)
        {
            std::cout << "\n\nC / Point" << "\ta\tb\tc\td\te\tf\tg\n";
            std::cout << "\t\t-\t-\t-\t-\t-\t-\t-";
        }
        for(unsigned int i=7; i<gd_vFer.size(); i++)
        {
            if((i%7)==0)
            {
                std::cout <<  '\n';
                if(writeCycles)
                    std::cout << "Cycle " << (i/7) << ":\t";
                std::cout << gd_vFer.at(i) << '\t';
            }
            else{
                    std::cout << gd_vFer.at(i) << '\t';
            }
        }

        std::cout << '\n';
    }
}

void globalData::write(char what)
{
    std::ofstream myfile;
    myfile.open ("data.txt", std::ios_base::app);
    if(myfile.is_open())
    {
        if(what=='a')
            for(unsigned int i=1; i<gd_vAnt.size(); i++)
                myfile << gd_vAnt.at(i) << '\n';

        if(what=='s')  // Ants summed with previous records
        {
            for(unsigned int i=1; i<gd_vAnt.size(); i++)
            {
                int val=0;
                for(int j=i; j>=0;j--)
                {
                    val+=gd_vAnt.at(j);
                }

                myfile << val << '\n';
            }
        }
        if(what=='f')
            for(unsigned int i=7; i<gd_vFer.size(); i++)
                if((i%7)==0)
                    myfile <<  '\n' << gd_vFer.at(i) << '\t';
                else
                    myfile << gd_vFer.at(i) << '\t';

        if(what=='a' || what=='s' || what=='f') myfile << '\n';

        myfile.close();
    }
}

void globalData::writeMax(char what)
{
    std::ofstream myfile;
    myfile.open ("data.txt", std::ios_base::app);
    if(myfile.is_open())
    {
        if(what=='s')  // Ants summed with previous records
        {
            int max=0;
            for(unsigned int i=1; i<gd_vAnt.size(); i++)
            {
                int val=0;
                for(int j=i; j>=0;j--)
                {
                    val+=gd_vAnt.at(j);
                }

                if(max<val) max=val;
            }
            myfile << max << '\n';
            myfile.close();

            gd_vAnt.clear();
        }

    }
}
