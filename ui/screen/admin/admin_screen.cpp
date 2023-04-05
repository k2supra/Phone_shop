#include "admin_screen.h"
#include "../screen.h"

void AdminScreen::displayPage(vector<PC>& pcList, int startIndex, int endIndex)
{
    auto const* pc_provider = new PCProvider();
    for (int i = startIndex; i < endIndex && i < pcList.size(); i++) {
        pc_provider->printMenuPC(&pcList[i]);
    }
    delete pc_provider;
}

void AdminScreen::menu()
{
    auto const* pc_provider = new PCProvider();
    vector<PC> pcdata;
    pc_provider->readPCData(pcdata);

    int pageNum = 0;
    int startIndex = pageNum * PAGE_SIZE;
    int endIndex = (pageNum + 1) * PAGE_SIZE;

    while (true) {
		double possiblePages = pcdata.size() / PAGE_SIZE;
		(pcdata.size() % PAGE_SIZE != 0) ? possiblePages++ : possiblePages = possiblePages;
        cout << "\n\n<-------------- PAGE " << pageNum + 1 << " ---------------->\n";
        displayPage(pcdata, startIndex, endIndex);
        cout << "<---                              --->\n  w                                 e  \n\na - add new PC\nd - delete PC\nq - exit\n";
        cout << "\nInput action -> ";
        string action;
        std::getline(cin, action);
        std::stringstream ss1(action);
        std::stringstream ss2(action); // tried to do it with one ss, but it didn't work
        int num;
        char ch;
        ss1 >> num;
        ss2 >> ch;
        if (ch == 'e' && pageNum + 1 != possiblePages)
        {
            pageNum++;
        }
        else if (ch == 'w' && pageNum > 0)
        {
            pageNum--;
        }
        else if (ch == 'q')
        {
            break;
        }
        else if (ch == 'a')
        {
            system("cls");
            cout << "\n<-------------- ADDING NEW PC ---------------->\n";
            string brand, model, processor, graphicsCard, operatingSystem;
            int ram, storage, price;
            cout << "Enter Brand: ";
            getline(cin, brand);
            
            cout << "Enter Model: ";
            getline(cin, model);

            cout << "Enter Processor: ";
            getline(cin, processor);

            cout << "Enter Ram: ";
            cin >> ram;

            cout << "Enter Storage: ";
            cin >> storage;

	        cin.ignore();
            cout << "Enter Graphics Card: ";
            getline(cin, graphicsCard);

            cout << "Enter Operating System: ";
            getline(cin, operatingSystem);

            cout << "Enter Price: ";
            cin >> price;
            
            std::fstream file("data/pcdata.csv", std::ios::app);
            if (file.is_open())
            {
                file << brand << "," << model << "," << processor << "," << ram << "," << storage << "," << graphicsCard << "," << operatingSystem << "," << '\n';
            }
            file.close();
            cout << "\nYour PC is published\n";

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // no more cin buffer bugs

            pcdata.clear();
            pc_provider->readPCData(pcdata); // update pcdata array

            system("pause>0");
        }
        else if (ch == 'd')
        {
            system("cls");
            cout << "\n<-------------- DELETING PC ---------------->\n";
            cout << "Enter id of PC to delete: ";
            uint64_t id;
            cin >> id;
            cout << "Are you sure?" << endl;
            cout << "\ny - yes \tn - no\n" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y')
            {
                vector<string> rows;
                std::ifstream del_file("data/pcdata.csv");
                string row;

                while (getline(del_file, row)) {
                    rows.push_back(row);
                }

                del_file.close();

                rows.erase(rows.begin() + id - 1);

                std::ofstream outfile("data/pcdata.csv");

                for (int i = 0; i < rows.size(); i++) {
                    outfile << rows[i] << '\n';
                }

                outfile.close();

				cout << "\nYour PC is deleted\n";
				system("pause>0");
            }

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // no more cin buffer bugs

            pcdata.clear();
            pc_provider->readPCData(pcdata); // update pcdata array
        }
        else if (num > 0 && num < pcdata.size() + 1)
        {
            system("cls");
			PC *curr_pc = &pcdata[num - 1];
            pc_provider->printPC(curr_pc);
            pc_provider->printComment(curr_pc);
            cout << "\nr - edit PC\na - add new comment\nd - delete comment\nq - exit";
            
            cout << "\nInput action -> ";

            char com_ch;
            cin >> com_ch;
            
            if (com_ch == 'a')
            {
                cin.ignore();
				system("cls");
				string comment_nickname = current_user->getName();
				string comment_text;
				cout << "\n<-------------- CREATING NEW COMMENT ---------------->\n";
				cout << "Enter your comment -> ";
				getline(cin, comment_text);

				std::ifstream rfile("data/pcdata.csv");
                std::vector<string> lines;
                string line;
                while (getline(rfile, line))
                {
                    lines.push_back(line);
                }
                
                lines[num - 1] += comment_nickname + ':' + comment_text + ';';

				std::ofstream wfile("data/pcdata.csv");
                for (const auto& l : lines)
                {
                    wfile << l << '\n';
                }
                wfile.close();

				cout << "\nYour comment is published\n";

				pc_provider->updatePC(curr_pc);  // updating PC

				system("pause>0");
            }
            else if (com_ch == 'r')
            {
                cin.ignore();
                system("cls");
                pc_provider->printPC(curr_pc);
                cout << "\n<-------------- EDITING PC ---------------->\n";
                cout << "\nChoose a parameter to edit [\n| 1 - brand \n| 2 - model \n| 3 - processor \n| 4 - RAM \n| 5 - storage \n| 6 - graphics card \n| 7 - operating system \n| 8 - price ]: ";
                int del_ch;
                cin >> del_ch;
                string delimiter = ",";

                string part_1_pc;
                int pos_1_pc = 0;
                string part_2_pc;
                int pos_2_pc_s = 0;
                int pos_2_pc_f = 0;
                string part_3_pc;
                int pos_3_pc = 0;
                
                int current_line = 0;

                std::fstream e_file("data/pcdata.csv");
                std::ofstream temp_file("data/temp_pcdata.csv");
                string line;
                if (del_ch == 1)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {
                            
                            if ((pos_1_pc = line.find(delimiter)) != string::npos)
                            {
                                part_1_pc = line.substr(0, pos_1_pc);
                                cout << "\nEnter new brand: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(pos_2_pc_s + 1);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                cout << "\nNew brand: " << edit_pc ;
                                temp_file << edit_pc << part_2_pc << endl;
                            }
                        }                       
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if(del_ch == 2)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter)) != string::npos)
                            {
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new model: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew model: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 3)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new processor: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew processor: " << edit_pc;
                                /*cout << "\nPart 1: " << part_1_pc << "\nPart 2: " << part_2_pc << "\nPart 3: " << part_3_pc << endl;*/
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 4)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter, pos_1_pc)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new RAM: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew RAM: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 5)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter, pos_1_pc)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new storage: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew storage: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 6)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter, pos_1_pc)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new graphics card: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew graphics card: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 7)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter, pos_1_pc)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new operating system: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew operating system: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }
                }
                else if (del_ch == 8)
                {
                    while (getline(e_file, line))
                    {
                        current_line++;
                        if (current_line == num)
                        {

                            if ((pos_1_pc = line.find(delimiter, pos_1_pc)) != string::npos)
                            {
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                pos_1_pc = line.find(delimiter, pos_1_pc + 1);
                                part_1_pc = line.substr(0, pos_1_pc + 1);
                                cout << "\nEnter new price: ";
                                cin.ignore();
                                string edit_pc;
                                getline(cin, edit_pc);

                                pos_2_pc_s = part_1_pc.length();
                                pos_2_pc_f = line.find(delimiter, pos_2_pc_s);
                                part_2_pc = line.substr(pos_2_pc_s, pos_2_pc_f);
                                part_3_pc = line.substr(pos_2_pc_f, string::npos);
                                cout << "\nNew price: " << edit_pc;
                                temp_file << part_1_pc << edit_pc << part_3_pc << endl;
                            }
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }

                }

                e_file.close();
                temp_file.close();
                remove("data/pcdata.csv");
                rename("data/temp_pcdata.csv", "data/pcdata.csv");

                cout << "\nSUCCESS";
                system("pause>0");
            }
            else if (com_ch == 'd')
            {
				cin.ignore();
                system("cls");
                pc_provider->printComment(curr_pc);
                cout << "\n<-------------- DELETING COMMENT ---------------->\n\n";
                cout << "Enter user to delete: ";
                string user_del;
                getline(cin, user_del);

                cout << "Are you sure?" << endl;
                cout << "\ny - yes \tn - no\n\n->";
                char choice;
                cin >> choice;
                if (choice == 'y')
                {
                    std::fstream r_file("data/pcdata.csv");
                    std::ofstream temp_file("data/temp_pcdata.csv");

                    string line;
                    string delimiter = ";";

                    string part_1_comment;
                    int pos_1_com = 0;
                    string part_2_comment;
                    int pos_2_com_s = 0;
                    int pos_2_com_f = 0;
                    string part_3_comment;
                    int pos_3_com = 0;

                    while (getline(r_file, line))
                    {

                        if ((pos_1_com = line.find(user_del)) != string::npos)
                        {
                            part_1_comment = line.substr(0, pos_1_com);
                            pos_2_com_s = part_1_comment.length();
                            pos_2_com_f = line.find(delimiter, pos_2_com_s);
                            part_2_comment = line.substr(pos_2_com_s, pos_2_com_f);
                            part_3_comment = line.substr(pos_2_com_f + 1, line.length());
                            temp_file << part_1_comment << part_3_comment << endl;
                        }
                        else
                        {
                            temp_file << line << endl;
                        }
                    }

                    r_file.close();
                    temp_file.close();
                    remove("data/pcdata.csv");
                    rename("data/temp_pcdata.csv", "data/pcdata.csv");

                    pc_provider->updatePC(curr_pc);
                    cout << "\nSUCCESS";
                }
            }
            else if (com_ch != 'q')
            {
                cout << "Error: wrong input!\n";
				system("pause>0");
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
        system("cls");
        startIndex = pageNum * PAGE_SIZE;
        endIndex = (pageNum + 1) * PAGE_SIZE;
    }
}

