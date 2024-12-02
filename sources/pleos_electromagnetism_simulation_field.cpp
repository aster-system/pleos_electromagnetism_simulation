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
    // Quadratic gradient color for the Image class circle, made for electromagnetic fields
    scls::Color fill_circle_gradient_electromagnetic(double distance, int radius, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
        double needed_multiplication = std::pow(std::abs(1.0 - distance / static_cast<double>(radius)), 2);
        return scls::Color(static_cast<double>(red) * needed_multiplication, static_cast<double>(green) * needed_multiplication, static_cast<double>(blue) * needed_multiplication, static_cast<double>(alpha) * needed_multiplication);
    }

    // Electromagnetism_Field constructor
    Electromagnetism_Field::Electromagnetism_Field(scls::_Window_Advanced_Struct& window, std::string name, scls::GUI_Object* parent) : scls::GUI_Object(window, name, parent) {
        set_texture_alignment(scls::Alignment_Texture::T_Fit);
    }

    // Adds an electrical charge in the field
    void Electromagnetism_Field::add_electrical_charge(double charge, scls::Fraction x, scls::Fraction y) {
        // Create the object
        std::shared_ptr<Electrical_Charge> current_charge = std::make_shared<Electrical_Charge>(charge);
        current_charge.get()->set_x(x.to_double()); current_charge.get()->set_y(y.to_double());
        a_objects.push_back(current_charge);
    }

    // Function called after that the window is resized
    void Electromagnetism_Field::after_resizing() {scls::GUI_Object::after_resizing();load_field_texture();}

    // Loads the needed texture for the field
    void Electromagnetism_Field::load_field_texture() {
        // Create the new picture
        int height = height_in_pixel() / 2;
        int width = width_in_pixel() / 2;
        std::shared_ptr<scls::Image> new_texture = std::make_shared<scls::Image>(width, height, scls::Color(0, 0, 0));

        // Create the fields
        for(int i = 0;i<static_cast<int>(a_objects.size());i++) {
            scls::Transform_Object_3D position = field_position_to_gui_position(*(a_objects[i].get()));
            if(a_objects[i].get()->charge() > 0) {
                new_texture.get()->fill_circle_gradient(position.x(), position.y(), a_objects[i].get()->force_field_produced(1) * 50000, scls::Color(255, 0, 0), fill_circle_gradient_electromagnetic);
            } else {
                new_texture.get()->fill_circle_gradient(position.x(), position.y(), a_objects[i].get()->force_field_produced(1) * 50000, scls::Color(0, 0, 255), fill_circle_gradient_electromagnetic);
            }
        }

        texture()->set_image(new_texture);
    }

    // Field conversions
    scls::Transform_Object_3D Electromagnetism_Field::field_position_to_gui_position(const scls::Transform_Object_3D& position) {
        scls::Transform_Object_3D to_return;
        to_return.set_x(width_in_pixel() / 4 + (position.x() - a_middle.x()) * a_pixels_by_unit_width);
        to_return.set_y(height_in_pixel() / 4 + (position.y() - a_middle.y()) * a_pixels_by_unit_height);
        return to_return;
    }
}
