#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <queue>

namespace gparse {

class Command {
	public:
	std::string opcode;
	std::vector<std::string> pieces; //the command when split on spaces. Eg "G1 X2 Y3" -> ["G1", "X2", "Y3"]
	public:
		static const Command OK;
		//initialize the command object from a line of GCode
		Command() {}
		Command(std::string const&);
		std::string getOpcode() const;
		std::string toGCode() const;
		std::string getStrParam(char label) const;
		float getFloatParam(char label) const;
		float getX() const;
		float getY() const;
		float getE() const;
	private:
		void addPieceOrOpcode(std::string const& piece);
};

}
#endif