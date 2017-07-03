#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <FL/fl_ask.H>
#include <vector>
#include <iostream>
#include <fstream>
#include "window.h"

using namespace std;

class Data {
private:
	string id;
	string label;
public:
	Data(string id, string label) {
		this->id = id;
		this->label = label;
	}
	string getID() {
		return id;
	}
	string getLabel() {
		return label;
	}
	void setLabel(string label) {
		this->label = label;
	}
	void setID(string id) {
		this->id = id;
	}

};

class View : UserInterface {

protected:
	vector<Data> data;
	string title;

public:

	View() {
		btnTitle->callback((Fl_Callback*)cbBtnTitle, (void*)(this));
		btnAdd->callback((Fl_Callback*)cbBtnAdd, (void*)(this));
		btnDelete->callback((Fl_Callback*)cbBtnDelete, (void*)(this));
		btnLoad->callback((Fl_Callback*)cbBtnLoad, (void*)(this));
		btnStore->callback((Fl_Callback*)cbBtnStore, (void*)(this));
		browser->callback((Fl_Callback*)cbBrowser, (void*)(this));
	}

	void show() {
		w->show();
	}

	static void cbBtnAdd(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		string idInput(gui->idInput->value());
		string labelInput(gui->labelInput->value());
		gui->data.push_back(Data(idInput, labelInput));
		gui->browser->add(("Label: " + labelInput + " ; ID: " + idInput).c_str());
	}

	static void cbBrowser(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		int index = gui->browser->value(); // 1-based index
		gui->idInput->value(gui->data[index - 1].getID().c_str());
		gui->labelInput->value(gui->data[index - 1].getLabel().c_str());
	}

	static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		int index = gui->browser->value(); // 1-based index
		cout << index << endl;
		if (index > 0) {
			string idInput(gui->idInput->value());
			string labelInput(gui->labelInput->value());
			gui->data.erase(gui->data.begin() + index - 1);
			gui->browser->remove(index);
		}
	}

	static void cbBtnLoad(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		ifstream myfile;
		myfile.open("Settings.txt");
		string line;
		string cell[2];
		getline(myfile, gui->title);
		while (getline(myfile, line)) {
			getline(myfile, cell[0], '-');
			getline(myfile, cell[1]);
			gui->data.emplace_back(cell[1], cell[0]);			
		}
		myfile.close();
	}

	static void cbBtnStore(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		ofstream myfile;
		myfile.open("Settings.txt");
		myfile << gui->title << "\n";
		for(vector<Data>::iterator it = gui->data.begin(); it != gui->data.end(); ++it)
		{
			myfile << it->getLabel() << "-" << it->getID() << "\n";
		}
		myfile.close();
	}

	static void cbBtnTitle(Fl_Widget* btn, void* userdata) {
		View* gui = static_cast<View*>(userdata);
		gui->title = gui->titleInput->value();
	}


};

int main() {
	View gui;
	gui.show();
	return Fl::run();
}