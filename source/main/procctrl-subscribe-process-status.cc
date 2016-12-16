/// \file procctrl-subscribe-process-status.cc
/*
 *
 * procctrl-subscribe-process-status.cc source template automatically generated by a class generator
 * Creation date : jeu. sept. 29 2016
 *
 * This file is part of procctrl libraries.
 *
 * procctrl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * procctrl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with procctrl.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Remi Ete
 * @copyright Remi Ete
 */


#include "ProcCtrlInternal.h"
#include "ProcessManagerClient.h"

// -- tclap headers
#include "tclap/CmdLine.h"
#include "tclap/Arg.h"

class ProcessStatusPrinter
{
public:
  void print(const Json::Value &value)
  {
    Json::StyledWriter writer;
    std::cout << writer.write(value) << std::endl;
  }
};


int main(int argc, char **argv)
{
  if(argc != 2)
  {
    std::cout << "Usage: procctrl-subscribe-process-status host" << std::endl;
    return 1;
  }

  const std::string host(argv[1]);

  try
  {
    procctrl::client::ProcessManagerClient client(host);
    ProcessStatusPrinter printer;
    client.onProcessStatusReceived(&printer, &ProcessStatusPrinter::print);

    while(1)
      sleep(1);
  }
  catch(const procctrl::Exception &exception)
  {
    return 1;
  }

  return 0;
}
