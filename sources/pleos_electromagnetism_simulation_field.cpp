//******************
//
// pleos_electromagnetism_simulation_field.cpp
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
//
// The "Electromagnetism simulation" part aims science (physic) lessons.
// Its goal is to explain how works electromagnetism to everyone, by providing some cools visual animations.
//
// This file contains the source code of pleos_electromagnetism_simulation_field.h.
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

// Include pleos_electromagnetism_simulation_field.h
#include "../headers/pleos_electromagnetism_simulation_field.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Electromagnetism_Field constructor
    Electromagnetism_Field::Electromagnetism_Field(scls::_Window_Advanced_Struct& window, std::string name, scls::GUI_Object* parent) : scls::GUI_Object(window, name, parent) {
        set_texture_alignment(scls::Alignment_Texture::T_Fit);
    }

    // Function called after that the window is resized
    void Electromagnetism_Field::after_resizing() {scls::GUI_Object::after_resizing();load_field_texture();}

    // Loads the needed texture for the field
    void Electromagnetism_Field::load_field_texture() {
        // Create the new picture
        int height = height_in_pixel() / 2;
        int width = width_in_pixel() / 2;
        std::shared_ptr<scls::Image> new_texture = std::make_shared<scls::Image>(width, height, scls::Color(0, 0, 0));
        texture()->set_image(new_texture);
    }
}
