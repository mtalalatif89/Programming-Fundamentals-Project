#include <iostream>
#include <fstream>
using namespace std;
void ecomstore();
void seeinventory();
void addtocart();
void addproduct(char **products, char ***ptr2, int &rows, int &cols, int &cart, int &cart_col);
int main()
{
    cout << endl;
    cout << "╔════════════════════════════════════════════=\n";
    cout << "║        WELCOME TO ECOM-STORE                 ║\n";
    cout << "╠════════════════════════════════════════════==╣\n";
    cout << "║                                              ║\n";
    cout << "║   [1]   Browse & Order Products              ║\n";
    cout << "║   [3]   Exit                                 ║\n";
    cout << "║                                              ║\n";
    cout << "╚════════════════════════════════════════════===\n";
    int choice = 0;
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        ecomstore();
    }
    if (choice == 3)
    {
        cout << "Exiting --- Bye" << endl;
    }
    return 0;
}
void ecomstore()
{
    cout << endl;
    cout << "  ╔═══════════════════════════════════════==═══╗\n";
    cout << "  ║          ORDER PRODUCTS                    ║\n";
    cout << "  ╠════════════==══════════════════════════════╣\n";
    cout << "  ║   [1] 📋  View Available Products          ║\n";
    cout << "  ║   [5] 🔙  Back to Main Menu                ║\n";
    cout << "  ╚════════════════════════════════════════════╝\n";
    cout << "Enter your choice (1-5): ";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        seeinventory();
    }
    if (choice == 5)
    {
        cout << endl;
        cout << "╔════════════════════════════════════════════===\n";
        cout << "║        WELCOME TO ECOM-STORE                 ║\n";
        cout << "╠════════════════════════════════════════════==╣\n";
        cout << "║                                              ║\n";
        cout << "║   [1] 🛒  Browse & Order Products            ║\n";
        cout << "║   [3] ❌  Exit                               ║\n";
        cout << "║                                              ║\n";
        cout << "╚════════════════════════════════════════════===\n";
    }
    cin >> choice;
    if (choice == 1)
    {
        seeinventory();
    }
}
void seeinventory()
{
    ifstream inventory;
    inventory.open("Inventory.txt");
    if (inventory.is_open())
    {
        int rows = 8;
        int col = 80;
        int r1 = 0;
        char **products = new char *[rows];
        for (int i = 0; i < rows; i++)
        {
            products[i] = new char[col];
        }
        for (int i = 0; i < rows; i++)
        {
            products[i][0] = '\0';
        }
        char ch1;
        int bar_counter = 0;
        int idcount = 0;
        int i1 = 0;
        char *idarray = new char[200];
        while (inventory.get(ch1))
        {
            if (bar_counter < 1 && ch1 != '|')
            {
                if (ch1 >= '0' && ch1 <= '9')
                {
                    idarray[idcount] = ch1;
                    idcount++;
                }
            }
            if (ch1 == '|')
            {
                // This step will check what is the count of bar if it is =1 it will make a column array for storing
                // id
                if (bar_counter <= 5)
                {
                    for (int j = 0; j < idcount; j++)
                    {
                        if (idarray[j] != '\0')
                        {
                            products[r1][i1] = idarray[j];
                            i1++;
                        }
                    }
                    if (bar_counter < 5)
                    { // Only add space if not the last field (stock)
                        products[r1][i1] = ' ';
                        i1++;
                    }
                    idcount = 0;
                    for (int i = 0; i < 200; i++)
                    {
                        idarray[i] = '\0';
                    }
                    bar_counter++;
                    continue;
                }
            }
            if (bar_counter == 1 && ch1 != '|' && ch1 != '\r')
            {
                idarray[idcount] = ch1;
                idcount++;
            }
            if (bar_counter == 2 && ch1 != '|' && ch1 != '\r')
            {
                idarray[idcount] = ch1;
                idcount++;
            }
            if (bar_counter == 3 && ch1 != '|' && ch1 != '\r')
            {
                idarray[idcount] = ch1;
                idcount++;
            }
            if (bar_counter == 4 && ch1 != '|' && ch1 != '\r')
            {
                idarray[idcount] = ch1;
                idcount++;
            }
            if (bar_counter == 5 && ch1 != '|')
            {
                idarray[idcount] = ch1;
                idcount++;
            }
            if (ch1 == '\n' && ch1 != '\r')
            {
                bar_counter = 0;
                r1++;
                for (int i = 0; i < 200; i++)
                {
                    idarray[i] = '\0';
                }
                i1 = 0;
            }
        }
        delete[] idarray;
        idarray = nullptr;
        // Now we will display:-
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << products[i][j];
            }
            cout << endl;
        }
        cout << "Do u want to add a product to the cart:-";
        cout << "\n Type 1 if u want to add the product to the cart";
        int choice2;
        cin >> choice2;
        if (choice2 == 1)
        {
            int cart_rows = 0, cart_col = 100;
            cout << "How many Products do u want to add to the cart:-";
            cin >> cart_rows;
            cin.ignore();
            char **ptr2 = new char *[cart_rows];
            for (size_t i = 0; i < cart_rows; i++)
            {
                ptr2[i] = new char[cart_col];
            }
            for (int i = 0; i < cart_rows; i++)
            {
                cout << "Enter the id of" << i << "product u want to add to the cart:-";
                char ch3[4];
                cin.getline(ch3, 4);
                int space = 0;
                bool matched = false;
                int rmatch = -9;
                int counter = 0;
                for (int i1 = 0; i1 < 8; i1++)
                {
                    int totalMatched = 0; // ← ADD THIS
                    int totalChars = 0;   // ← ADD THIS
                    int x = 0;
                    for (; ch3[counter] != '\0'; counter++)
                    {
                        totalChars++;
                        if (products[i1][counter] == ' ')
                        {
                            space++;
                        }
                        if ((products[i1][counter] >= '0' && products[i1][counter] <= '9') && (products[i1][counter] == ch3[counter]) && space < 1)
                        {
                            x = 1;
                            totalMatched++;
                        }
                        if ((products[i1][counter] >= '0' && products[i1][counter] <= '9') && (products[i1][counter] != ch3[counter]) && space < 1)
                        {
                            x = 0;
                        }
                        if (space > 0)
                        {
                            if (totalMatched == totalChars)
                            {
                                matched = true;
                            }
                            else
                            {
                                matched = false;
                            }
                            break;
                        }
                    }
                    if (space == 0 && x == 1 && products[i1][counter] == ' ')
                    {
                        matched = true;
                    }
                    if (matched == true)
                    {
                        rmatch = i1;
                        cout << rmatch;
                        counter = 0;
                        space = 0;
                        break;
                    }
                    else
                    {
                        counter = 0;
                        space = 0;
                        matched = false;
                        rmatch = -9;
                    }
                }
                if (matched == false)
                {
                    cout << "Id doesn't exists:(\n Plz Enter Again:-" << endl;
                    i--;
                    continue;
                }

                // matched == true, proceed to copy
                cout << "Id exists:-" << "Procedding to next steps:-" << endl;

                // Intialize ptr2 to 0 so no error:-
                // Intialize ptr2 to 0 so no error:-
                for (int h = 0; h < 100; h++)
                {
                    ptr2[i][h] = '\0';
                }
                if (rmatch >= 0)
                {
                    int s = 0;
                    for (int j = 0; j < 80 && products[rmatch][j] != '\0'; j++)
                    {
                        if (products[rmatch][j] == ' ')
                        {
                            s++;
                        }
                        if (s < 5)
                        {
                            ptr2[i][j] = products[rmatch][j];
                        }
                        if (s == 5)
                        {
                            ptr2[i][j] = ' ';
                            int j1=j+1;
                            ptr2[i][j1]='1';
                            j1++;
                            ptr2[i][j1] = '\0'; // ← Add this
                            break;
                        }
                    }
                    cout << "\n1 quantity of this Product added to cart success:)";
                    cout << "\n"
                         << ptr2[i] << endl;
                }
                cout << "DEBUG: ptr2[i] = '" << ptr2[i] << "'" << endl;
            }
            cout << "For CheckOut press 2 for removing a product or adding a product or changing its quantity press 4";
            int choice4;
            cin >> choice4;
            if (choice4 == 4)
            {
                inventory.close();
                addproduct(products, &ptr2, rows, col, cart_rows, cart_col);
            }
            if (choice4 == 2) // Checkout
            {
                if (cart_rows == 0)
                {
                    cout << "Cart is empty!" << endl;
                    return;
                }

                // Show cart
                cout << "\n Your Cart:" << endl;
                for (int i = 0; i < cart_rows; i++)
                {
                    cout << i + 1 << ". " << ptr2[i] << endl;
                }
                // First Name
                char fname[50];
                cin.ignore();
                while (true)
                {
                    cout << "Enter First Name (letters only): ";
                    cin.getline(fname, 50);

                    bool valid = true;
                    for (int i = 0; fname[i] != '\0'; i++)
                    {
                        if (!((fname[i] >= 'A' && fname[i] <= 'Z') || (fname[i] >= 'a' && fname[i] <= 'z') || fname[i] == ' '))
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid && fname[0] != '\0')
                        break;
                    cout << "Invalid! Use only letters." << endl;
                }

                // Last Name
                char lname[50];
                while (true)
                {
                    cout << "Enter Last Name (letters only): ";
                    cin.getline(lname, 50);

                    bool valid = true;
                    for (int i = 0; lname[i] != '\0'; i++)
                    {
                        if (!((lname[i] >= 'A' && lname[i] <= 'Z') || (lname[i] >= 'a' && lname[i] <= 'z') || lname[i] == ' '))
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid && lname[0] != '\0')
                        break;
                    cout << "Invalid! Use only letters." << endl;
                }

                // Phone (11 digits only)
                char phone[12];
                while (true)
                {
                    cout << "Enter Phone Number (11 digits): ";
                    cin.getline(phone, 12);

                    bool valid = true;
                    int len = 0;
                    for (int i = 0; phone[i] != '\0'; i++)
                    {
                        len++;
                        if (!(phone[i] >= '0' && phone[i] <= '9'))
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid && len == 11)
                        break;
                    cout << "Invalid! Must be 11 digits." << endl;
                }

                // Postal Code (5 digits only)
                char postal[6];
                while (true)
                {
                    cout << "Enter Postal Code (5 digits): ";
                    cin.getline(postal, 6);

                    bool valid = true;
                    int len = 0;
                    for (int i = 0; postal[i] != '\0'; i++)
                    {
                        len++;
                        if (!(postal[i] >= '0' && postal[i] <= '9'))
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid && len == 5)
                        break;
                    cout << "Invalid! Must be 5 digits." << endl;
                }

                // Address (any)
                char address[300];
                cout << "Enter Address: ";
                cin.getline(address, 300);

                // Write to file
                ofstream userinfo("UserInfo.txt", ios::app);
                if (userinfo.is_open())
                {
                    userinfo << "========================================\n";
                    userinfo << "First Name: " << fname << "\n";
                    userinfo << "Last Name: " << lname << "\n";
                    userinfo << "Phone: " << phone << "\n";
                    userinfo << "Postal Code: " << postal << "\n";
                    userinfo << "Address: " << address << "\n";
                    userinfo << "----------------------------------------\n";
                    userinfo << "Products Ordered:\n";

                    for (int i = 0; i < cart_rows; i++)
                    {
                        userinfo << ptr2[i] << "\n";
                    }

                    userinfo << "========================================\n\n";
                    userinfo.close();

                    cout << "\nOrder placed successfully!" << endl;
                    cout << "Thanks for Shopping :<\n See you Again" << endl;
                    for (int i = 0; i < rows; i++)
                    {
                        delete[] products[i];
                    }
                    delete[] products;
                    products = nullptr;
                    exit(0);
                }
                else
                {
                    cout << "Error saving order!" << endl;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] products[i];
        }
        delete[] products;
        products = nullptr;
    }
}
void addproduct(char **products, char ***ptr2, int &rows, int &cols, int &cart, int &cart_col)
{
    int ch1;
    cout << "\n1-For changing quantity Press 0\n2-For adding a product press 1\n3-For Removing a product press 2\n4-For moving to checkout press 3" << endl;
    cin >> ch1;
    cin.ignore();

    if (ch1 == 0)
    {
        for (size_t i = 0; i < cart; i++)
        {
            cout << (*ptr2)[i] << endl;
        }
        char ch3[4];
        cout << "Enter the id of the product u want to change the quantity of:-";
        cin.getline(ch3, 4);
        int n = 0;
        int i1 = 0;
        for (size_t i = 0; i < cart; i++)
        {
            int n = 0;
            bool matched = false;
            for (size_t j = 0; j < cart_col; j++)
            {
                if ((*ptr2)[i][j] != ' ' && n == 0 && ((*ptr2)[i][j] >= '0' && (*ptr2)[i][j] <= '9'))
                {
                    if (ch3[j] != '\0')
                    {
                        if (ch3[j] == (*ptr2)[i][j])
                        {
                            matched = true;
                        }
                    }
                }
                if ((*ptr2)[i][j] == ' ')
                {
                    n = 1;
                    break;
                }
            }
            if (matched == true)
            {
                n = 0;
                i1 = i;
                cout << "True";
                break;
            }
        }
        int bar_counter = 0;
        for (int j = 0; j < cart_col; j++)
        {
            if ((*ptr2)[i1][j] == ' ')
            {
                bar_counter++;
            }
            if (bar_counter == 5)
            {
                char ch4[3];
                cout << "Enter the quantity b/w 1-99";
                cin.getline(ch4, 3);
                int g = j + 1;
                int count = 0;
                for (int i = 0; i < ch4[i] != '\0'; i++)
                {
                    int x = i + 1;
                    if (ch4[x] == '\0')
                    {
                        count++;
                    }
                    if (count == 1)
                    {
                        (*ptr2)[i1][g] = ch4[i];
                        g++;
                        for (int d = g; d < cart_col; d++)
                        {
                            (*ptr2)[i1][d] = '\0';
                        }
                        break;
                    }
                    else
                    {
                        (*ptr2)[i1][g] = ch4[i];
                        g++;
                        int i6 = i + 1;
                        (*ptr2)[i1][g] = ch4[i6];
                        g++;
                        for (int d = g; d < cart_col; d++)
                        {
                            (*ptr2)[i1][d] = '\0';
                        }
                        break;
                    }
                }
                break;
            }
        }
        cout << (*ptr2)[i1] << endl;
        cout << "Product quantity has been changed successfully:>>";
        cout << "Do u want to move to checkout or want to add products:-";
        cout << endl
             << "Press 1 for adding more products 2 for checkout 3 for removing a product:-";
        cin >> ch1;
    }
    if (ch1 == 1)
    {
        int r1;
        cout << "Enter No of items u want to further add to the cart:-";
        cin >> r1;
        cout << endl;
        int cart_extend = cart + r1;
        cin.ignore();
        char **ptr3 = new char *[cart_extend];
        // This step would make further rows:-
        for (int i = 0; i < cart_extend; i++)
        {
            ptr3[i] = new char[cart_col];
        }
        int k = 0;
        // This step would copy data from ptr2;
        for (int i = 0; i < cart; i++)
        {
            for (int j = 0; j < cart_col; j++)
            {
                ptr3[i][j] = (*ptr2)[i][j];
            }
            k = i;
        }
        // Now we would display the menu to the user:-
        cout << "Here is a Product List which products do u want to add:-" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << products[i] << endl;
        }
        // Now we will ask user to enter id:-
        k = k + 1;
        for (int i5 = k; i5 < cart_extend; i5++)
        {
            char ch3[4];
            cout << "\nEnter the id of the product u want to change the quantity of:-";
            cin.getline(ch3, 4);
            bool matched = false;
            int i1 = 0;
            for (size_t i = 0; i < cart; i++)
            {
                int n = 0;
                for (size_t j = 0; j < cart_col; j++)
                {
                    if (ptr3[i][j] != ' ' && n == 0 && (ptr3[i][j] >= '0' && ptr3[i][j] <= '9'))
                    {
                        if (ch3[j] != '\0')
                        {
                            if (ch3[j] == ptr3[i][j])
                            {
                                matched = true;
                            }
                        }
                    }
                    if (ptr3[i][j] == ' ')
                    {
                        n = 1;
                        break;
                    }
                }
                if (matched == true)
                {
                    n = 0;
                    i1 = i;
                    cout << "True";
                    break;
                }
            }
            // Now we will check if id got matched then we will update quantity not add products:-
            if (matched == true)
            {
                cout << "The thing is that product already exists in the cart so now enter the quantity u want to update:-" << endl;
                int bar_counter = 0;
                for (int j = 0; j < cart_col; j++)
                {
                    if (ptr3[i1][j] == ' ')
                    {
                        bar_counter++;
                    }
                    if (bar_counter == 5)
                    {
                        char ch4[3];
                        cout << "Enter the quantity b/w 1-99";
                        cin.getline(ch4, 3);
                        int g = j + 1;
                        int count = 0;
                        for (int i = 0; i < ch4[i] != '\0'; i++)
                        {
                            int x = i + 1;
                            if (ch4[x] == '\0')
                            {
                                count++;
                            }
                            if (count == 1)
                            {
                                ptr3[i1][g] = ch4[i];
                                g++;
                                for (int d = g; d < cart_col; d++)
                                {
                                    ptr3[i1][d] = '\0';
                                }
                                break;
                            }
                            else
                            {
                                ptr3[i1][g] = ch4[i];
                                g++;
                                int i6 = i + 1;
                                ptr3[i1][g] = ch4[i6];
                                g++;
                                for (int d = g; d < cart_col; d++)
                                {
                                    ptr3[i1][d] = '\0';
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            if (matched == false)
            {
                // Search in inventory (products array)
                int invIndex = -1;
                for (int p = 0; p < rows; p++)
                {
                    bool found = true;
                    int j = 0;

                    // Compare ID character by character
                    while (ch3[j] != '\0' && products[p][j] != ' ' && products[p][j] != '\0')
                    {
                        if (ch3[j] != products[p][j])
                        {
                            found = false;
                            break;
                        }
                        j++;
                    }

                    // Check if both strings ended at the same point
                    if (found && (ch3[j] == '\0' || ch3[j] == ' ') &&
                        (products[p][j] == ' ' || products[p][j] == '\0'))
                    {
                        invIndex = p;
                        break;
                    }
                }

                if (invIndex != -1)
                {
                    // Product found in inventory → Copy to ptr3[i5]
                    for (int j = 0; j < cart_col && products[invIndex][j] != '\0'; j++)
                    {
                        ptr3[i5][j] = products[invIndex][j];
                    }
                    ptr3[i5][cart_col - 1] = '\0';
                    cout << "New product added to cart!" << endl;
                    cout << ptr3[i5];
                }
                else
                {
                    cout << "Product ID not found in inventory!" << endl;
                }
            }
        }
        cout << "To move to Checkout Press 3\n For Removing a Product press 2";
        cin >> ch1;
        // Now we will clear out old data from ptr2;
        for (int i = 0; i < cart; i++)
        {
            delete[] (*ptr2)[i];
        }
        *ptr2 = ptr3;
        cart = cart_extend;
    }
    if (ch1 == 2)
    {
        cout << "Here is the Number of Products that are in the cart:-\n";
        for (int i = 0; i < cart; i++)
        {
            cout << (*ptr2)[i] << endl;
        }
        cout << "Enter Number of Products u want to delete:-";
        int n = 0;
        cin >> n;
        int n1 = 0;
        int deletecount = 0;
        while (true)
        {
            if (n > 0 && n <= cart)
            {
                break;
            }
            else
            {
                cout << "U can't add a negative number or a number greator than cart data:-" << endl
                     << "Enter Again:-";
                cin >> n;
            }
        }
        deletecount = n;
        n1 = cart - n;
        // We will make a temp array so that we can store data here:-
        char **temp = new char *[n1];
        for (int i = 0; i < cart; i++)
        {
            int end = 0;
            for (int j = 0; j < cart_col && (*ptr2)[i][j] != '\0'; j++)
            {
                end = j;
            }
            // Find last non-space
            while (end > 0 && (*ptr2)[i][end] == ' ')
            {
                end--;
            }
            (*ptr2)[i][end + 1] = '\0';
        }
        // Now we will intialize columns:-
        for (int i = 0; i < n1; i++)
        {
            temp[i] = new char[cart_col];
        }
        for (int i = 0; i < n1; i++)
        {
            temp[i][cart_col - 1] = '\0'; // Ensure null termination
        }
        cout << "Enter the Id of the product u want to delete:-";
        char ch5[4];
        cin.ignore();
        cin.getline(ch5, 4);
        int *wherefound = new int[deletecount];
        for (int i = 0; i < deletecount; i++)
        {
            wherefound[i] = -1;
        }
        int d = 0;
        int d1 = 0;
        for (int i = 0; i < cart; i++)
        {
            int scount = 0;
            int found = 0;
            for (int j = 0; j < cart_col; j++)
            {
                if ((*ptr2)[i][j] == ' ')
                {
                    scount++;
                }
                if (scount == 0)
                {
                    if ((*ptr2)[i][j] == ch5[j])
                    {
                        found = 1;
                        cout << "True";
                    }
                    if ((*ptr2)[i][j] != ch5[j])
                    {
                        cout << "Not Found";
                        cout << "Value in ptr2 is" << (*ptr2)[i][j] << endl;
                        cout << "Value in ch5=" << ch5[j];
                        break;
                    }
                }
                if (scount > 0)
                {
                    if (found == 1)
                    {
                        scount = 0;
                        break;
                    }
                    else
                    {
                        if (found == 0)
                        {
                            break;
                        }
                    }
                }
            }
            if (found == 1)
            {
                wherefound[d1] = i;
                // This would reset id array:-
                for (int i = 0; i < 5; i++)
                {
                    ch5[i] = '\0';
                }
                d++;
                d1++;
                if (d < deletecount)
                {
                    cout << "Enter the Id of the product u want to delete:-";
                    cin.getline(ch5, 4);
                }
                if (d == deletecount)
                {
                    break;
                }
            }
        }

        // Now we will throw data in temp and copy data from temp to ptr2;
        int destIndex = 0;
        for (int i = 0; i < cart; i++)
        {
            // Check if this index should be deleted
            bool skip = false;
            for (int k = 0; k < deletecount; k++)
            {
                if (wherefound[k] == i)
                {
                    skip = true;
                    break;
                }
            }

            // If not marked for deletion, copy to temp
            if (!skip)
            {
                int j = 0;
                // Copy until null terminator
                while (j < cart_col && (*ptr2)[i][j] != '\0')
                {
                    temp[destIndex][j] = (*ptr2)[i][j];
                    j++;
                }
                // Null terminate at the end of the string
                temp[destIndex][j] = '\0';
                destIndex++;
            }
        }

        // Delete old cart
        for (int i = 0; i < cart; i++)
        {
            delete[] (*ptr2)[i];
        }
        delete[] (*ptr2);

        // Point to new cart
        *ptr2 = temp;

        // Update cart size
        cart = cart - deletecount;

        cout << deletecount << " product(s) removed!" << endl;
        cout << " Cart now has " << cart << " items." << endl;
        cout << "Do u want to move to Checkout for Checkout press 3";
        cin >> ch1;
    }
    if (ch1 == 3)
    {
        if (cart == 0)
        {
            cout << "Cart is empty!" << endl;
            return;
        }

        // Show cart
        cout << "\n🛒 Your Cart:" << endl;
        for (int i = 0; i < cart; i++)
        {
            cout << i + 1 << ". " << (*ptr2)[i] << endl;
        }

        // First Name (letters only)
        char fname[50];
        cin.ignore();
        while (true)
        {
            cout << "Enter First Name (letters only): ";
            cin.getline(fname, 50);

            bool valid = true;
            for (int i = 0; fname[i] != '\0'; i++)
            {
                if (!((fname[i] >= 'A' && fname[i] <= 'Z') || (fname[i] >= 'a' && fname[i] <= 'z') || fname[i] == ' '))
                {
                    valid = false;
                    break;
                }
            }
            if (valid && fname[0] != '\0')
                break;
            cout << "Invalid! Use only letters." << endl;
        }

        // Last Name (letters only)
        char lname[50];
        while (true)
        {
            cout << "Enter Last Name (letters only): ";
            cin.getline(lname, 50);

            bool valid = true;
            for (int i = 0; lname[i] != '\0'; i++)
            {
                if (!((lname[i] >= 'A' && lname[i] <= 'Z') || (lname[i] >= 'a' && lname[i] <= 'z') || lname[i] == ' '))
                {
                    valid = false;
                    break;
                }
            }
            if (valid && lname[0] != '\0')
                break;
            cout << "Invalid! Use only letters." << endl;
        }

        // Phone (11 digits only)
        char phone[12];
        while (true)
        {
            cout << "Enter Phone Number (11 digits): ";
            cin.getline(phone, 12);

            bool valid = true;
            int len = 0;
            for (int i = 0; phone[i] != '\0'; i++)
            {
                len++;
                if (!(phone[i] >= '0' && phone[i] <= '9'))
                {
                    valid = false;
                    break;
                }
            }
            if (valid && len == 11)
                break;
            cout << "❌ Invalid! Must be 11 digits." << endl;
        }

        // Postal Code (5 digits only)
        char postal[6];
        while (true)
        {
            cout << "Enter Postal Code (5 digits): ";
            cin.getline(postal, 6);

            bool valid = true;
            int len = 0;
            for (int i = 0; postal[i] != '\0'; i++)
            {
                len++;
                if (!(postal[i] >= '0' && postal[i] <= '9'))
                {
                    valid = false;
                    break;
                }
            }
            if (valid && len == 5)
                break;
            cout << "Invalid! Must be 5 digits." << endl;
        }

        // Address (any)
        char address[300];
        cout << "Enter Address: ";
        cin.getline(address, 300);

        // Write to file
        ofstream userinfo("UserInfo.txt", ios::app);
        if (userinfo.is_open())
        {
            userinfo << "========================================\n";
            userinfo << "First Name: " << fname << "\n";
            userinfo << "Last Name: " << lname << "\n";
            userinfo << "Phone: " << phone << "\n";
            userinfo << "Postal Code: " << postal << "\n";
            userinfo << "Address: " << address << "\n";
            userinfo << "----------------------------------------\n";
            userinfo << "Products Ordered:\n";

            for (int i = 0; i < cart; i++)
            {
                userinfo << (*ptr2)[i] << "\n";
            }

            userinfo << "========================================\n\n";
            userinfo.close();

            cout << "\n Order placed successfully!" << endl;
            for (int i = 0; i < cart; i++)
            {
                delete[] (*ptr2)[i];
                ptr2 = NULL;
                cout << "Thanks for Choosing Us Peace Out:)" << endl;
                exit(0);
            }
        }
        else
        {
            cout << "Error saving order!" << endl;
        }
    }
}