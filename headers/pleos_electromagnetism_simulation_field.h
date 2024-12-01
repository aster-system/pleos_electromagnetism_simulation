//******************
//
// pleos_electromagnetism_simulation_field.h
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Electromagnetism simulation" part aims science (physic) lessons.
// Its goal is to explain how works electromagnetism to everyone, by providing some cools visual animations.
//
// This file contains some objects to handle electromagnetic fields.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD
#define PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    class Electromagnetism_Field : public scls::GUI_Object {
        // Class representating a electromagnetic field in a GUI object
    public:
        // Electromagnetism_Field constructor
        Electromagnetism_Field(scls::_Window_Advanced_Struct& window, std::string name, scls::GUI_Object* parent);

        // Function called after that the window is resized
        virtual void after_resizing();
        // Function called after an XML loading
        virtual void after_xml_loading(){scls::GUI_Object::after_xml_loading();load_field_texture();};

        // Loads the needed texture for the field
        void load_field_texture();
    };
}

#endif // PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD
