#include "Event.h"

std::map <std::string, std::map<int, void(*)()>> _events;

void Event::addEvent(std::string type, void(*func)()){
	if (_events.find(type) == _events.end()){
		_events[type][0] = func;
	}
	else{
		_events[type][_events[type].size() - 1] = func;
	}
}

void Event::dispatchEvent(std::string type){
	if (_events.find(type) != _events.end()){
		for (int i = 0; i < _events.size(); i++){
			_events[type][i]();
		}
	}
}