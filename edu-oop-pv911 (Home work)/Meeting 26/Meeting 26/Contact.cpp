#include "header.h"

Contact::Contact() : company("def_Company"),  busyness("def_Busyness"),
					 owner  ("def_Owner"),    phone   ("def_Phone"),
					 address("def_Address")   { edit(); }

void Contact::edit()
{
	auto t_edit = [](string& field)
	{
		cout << " [old] " << std::left << setw(32) << field << std::right << "\t[new] ";
		std::getline(cin, field);
	};
	
	if (key->c || key->all) t_edit(company);
	if (key->b || key->all) t_edit(busyness);
	if (key->o || key->all) t_edit(owner);
	if (key->p || key->all) t_edit(phone);
	if (key->a || key->all) t_edit(address);
}

std::ostream& operator << (std::ostream& out, Contact& obj)
{
	if (key->c || key->all) out << setw(11) << "Company : " << obj.company  << '\n';
	if (key->b || key->all) out << setw(11) << "Busyness: " << obj.busyness << '\n';
	if (key->o || key->all) out << setw(11) << "Owner   : " << obj.owner    << '\n';
	if (key->p || key->all) out << setw(11) << "Phone   : " << obj.phone    << '\n';
	if (key->a || key->all) out << setw(11) << "Address : " << obj.address  << '\n';
	
	return out;
}

string& Contact::at(int index)
{
	if (index < 0 || index > 4) index = 0;
	
	if (index == 0) return company;
	if (index == 1) return busyness;
	if (index == 2) return owner;
	if (index == 3) return phone;
	if (index == 4) return address;
}