#include "window.h"
#include <FL/fl_ask.H>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;


class SelectorView : public MainFrame {

protected:
	vector<int> lst;

public:

	SelectorView() {
		btnSet->callback((Fl_Callback*)&setList, (void*)(this));
		btnPick->callback((Fl_Callback*)&pickList, (void*)(this));
	}

	void show() {
		w->show();
	}

	void setList(Fl_Widget* btn, void* userdata) {
		SelectorView* gui = static_cast<SelectorView*>(userdata);
		try
		{
			int q = stoi(gui->valueInput->value());
			lst.clear();

			for (int i = q; i > 0; i--)
			{
				lst.push_back(i);
			}
			random_shuffle(lst.begin(), lst.end());
		}
		catch (invalid_argument&)
		{
			fl_alert("Quantity deve ser um numero inteiro.");
		}
	}

	void pickList(Fl_Widget* btn, void* userdata) {
		SelectorView* gui = static_cast<SelectorView*>(userdata);

		if (lst.empty()) {
			gui->boxResult->label("Empty list");
		}
		else {
			gui->boxResult->copy_label(to_string(lst.back()));
			lst.pop_back();
		}
	}

};

int main() {

	SelectorView gui;
	gui.show();
	return Fl::run();
}

