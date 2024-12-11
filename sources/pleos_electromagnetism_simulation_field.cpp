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
    // Returns the texture of a magnet
    std::shared_ptr<scls::Image> magnet_texture(int width, int height) {
        std::shared_ptr<scls::Image> to_return = std::make_shared<scls::Image>(width, height, scls::Color(255, 0, 0));
        to_return.get()->fill_rect(0, 0, width / 2.0, height, scls::Color(0, 0, 255));
        return to_return;
    }

    // Quadratic gradient color for the Image class circle, made for electric fields
    scls::Color fill_circle_gradient_electric_field(double distance, int radius, int x, int y, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
        double needed_multiplication = std::pow(std::abs(1.0 - distance / static_cast<double>(radius)), 2);
        return scls::Color(static_cast<double>(red) * needed_multiplication, static_cast<double>(green) * needed_multiplication, static_cast<double>(blue) * needed_multiplication, static_cast<double>(alpha) * needed_multiplication);
    }
    scls::Color fill_circle_gradient_electric_field_div(double distance, int radius, int x, int y, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
        double needed_multiplication = 1.0;
        return scls::Color(static_cast<double>(red) * needed_multiplication, static_cast<double>(green) * needed_multiplication, static_cast<double>(blue) * needed_multiplication, static_cast<double>(alpha) * needed_multiplication);
    }
    // Quadratic gradient color for the Image class circle, made for magnetic fields
    double __needed_angle = 0;
    scls::Color fill_circle_gradient_magnetic_field(double distance, int radius, int x, int y, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
        // Apply the good color
        double created_angle = scls::vector_2d_angle(x, y);
        while(created_angle > SCLS_PI) {created_angle -= SCLS_PI * 2;}
        while(created_angle < -SCLS_PI) {created_angle += SCLS_PI * 2;}
        double needed_angle = created_angle + (__needed_angle);
        while(needed_angle > SCLS_PI) {needed_angle -= SCLS_PI * 2;}
        while(needed_angle < -SCLS_PI) {needed_angle += SCLS_PI * 2;}
        if(needed_angle < 0) {red = 125;}

        // Apply the equipotential
        double diff = std::abs((SCLS_PI - __needed_angle) - created_angle);
        while(diff > SCLS_PI / 2.0) {diff -= SCLS_PI;} diff = std::abs(diff);
        double added_multiplication = diff / (SCLS_PI / 2.0);
        added_multiplication = std::pow(added_multiplication, 1.0/2.0);

        // Apply the distance
        double needed_multiplication = std::pow(std::abs(1.0 - distance / static_cast<double>(radius)), 1) * added_multiplication;
        return scls::Color(static_cast<double>(red) * needed_multiplication, static_cast<double>(green) * needed_multiplication, static_cast<double>(blue) * needed_multiplication, static_cast<double>(alpha) * needed_multiplication);
    }

    // Electromagnetism_Field constructor
    Electromagnetism_Field::Electromagnetism_Field(scls::_Window_Advanced_Struct& window, std::string name, scls::GUI_Object* parent) : scls::GUI_Object(window, name, parent) {
        set_texture_alignment(scls::Alignment_Texture::T_Fit);
    }

    // Adds an electrical charge in the field
    std::shared_ptr<Electrical_Charge> Electromagnetism_Field::add_electrical_charge(double charge, double x, double y, double mass) {
        // Create the needed mass
        if(mass == -1) {
            mass = charge / std::pow(10, -6);
            mass = std::pow(mass, 2);
        }

        // Create the object
        std::shared_ptr<Electrical_Charge> current_charge = std::make_shared<Electrical_Charge>(charge);
        current_charge.get()->set_x(x); current_charge.get()->set_y(y); current_charge.get()->set_mass(mass);
        a_objects.push_back(current_charge);
        return current_charge;
    }

    // Adds a magnet in the field
    std::shared_ptr<Magnet> Electromagnetism_Field::add_magnet(double charge, double x, double y, double mass) {
        // Create the needed mass
        if(mass == -1) {
            mass = charge / std::pow(10, -6);
            mass = std::pow(mass, 2);
        }

        // Create the object
        std::shared_ptr<Magnet> current_magnet = std::make_shared<Magnet>();
        current_magnet.get()->physic.set_x(x); current_magnet.get()->physic.set_y(y); current_magnet.get()->physic.set_mass(mass);
        current_magnet.get()->charge = charge;
        current_magnet.get()->texture = magnet_texture(300, 50);
        a_magnets.push_back(current_magnet);
        return current_magnet;
    }

    // Adds a random electrical charge in the field
    void Electromagnetism_Field::add_random_electrical_charge(double min_charge, double max_charge, double min_x, double max_x, double min_y, double max_y) {
        double charge_number = (static_cast<double>(rand() % 100) / 100.0);
        double mass_ratio = (max_charge - min_charge) / std::pow(10, -6);
        double random_charge = min_charge + (max_charge - min_charge) * charge_number;
        double random_x = min_x + (max_x - min_x) * (static_cast<double>(rand() % 100) / 100.0);
        double random_y = min_y + (max_y - min_y) * (static_cast<double>(rand() % 100) / 100.0);
        // Get the mass
        double final_mass = std::abs(min_charge) / std::pow(10, -6) + 5.0 * mass_ratio * charge_number;
        final_mass = std::pow(final_mass, 2);
        std::shared_ptr<Electrical_Charge> current_charge = add_electrical_charge(random_charge, random_x, random_y, final_mass);
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
            // Create the electrical field
            scls::Vector_3D position = field_position_to_gui_position(a_objects[i].get()->attached_transform()->position());
            // Create the electrical field
            double force_field = a_objects[i].get()->force_field_produced(1) * 0.01;
            if(show_electrical_div()) {
                // Divergence of the electrical field
                if(a_objects[i].get()->charge() > 0) {
                    new_texture.get()->fill_circle_gradient(position.x(), position.y(), force_field, scls::Color(255, 0, 0), fill_circle_gradient_electric_field_div);
                } else {
                    new_texture.get()->fill_circle_gradient(position.x(), position.y(), force_field, scls::Color(0, 0, 255), fill_circle_gradient_electric_field_div);
                }
            } else {
                // Electrical field
                if(a_objects[i].get()->charge() > 0) {
                    new_texture.get()->fill_circle_gradient(position.x(), position.y(), force_field, scls::Color(255, 0, 0), fill_circle_gradient_electric_field);
                } else {
                    new_texture.get()->fill_circle_gradient(position.x(), position.y(), force_field, scls::Color(0, 0, 255), fill_circle_gradient_electric_field);
                }
            }

            if(show_magnetic_field()) {
                // Create the magnetical field
                double magnetical_force = force_field * a_objects[i].get()->velocity().norm() * 10;
                __needed_angle = scls::vector_2d_angle(a_objects[i].get()->velocity().x(), a_objects[i].get()->velocity().y());
                while(__needed_angle > SCLS_PI) {__needed_angle -= SCLS_PI * 2;}
                while(__needed_angle < -SCLS_PI) {__needed_angle += SCLS_PI * 2;}
                new_texture.get()->fill_circle_gradient(position.x(), position.y(), magnetical_force, scls::Color(0, 255, 0), fill_circle_gradient_magnetic_field);
            }

            if(show_trajectory()) {
                // Create the trajectory
                scls::Vector_3D forward_position = a_objects[i].get()->attached_transform()->position() + a_objects[i].get()->velocity();
                forward_position = field_position_to_gui_position(forward_position);
                new_texture.get()->draw_line(position.x() - 1, position.y() - 1, forward_position.x() - 1, forward_position.y() - 1, scls::Color(255, 255, 255), 2);
            }

            if(show_acceleration()) {
                // Create the acceleration
                scls::Vector_3D forward_position = a_objects[i].get()->attached_transform()->position() + a_objects[i].get()->acceleration();
                forward_position = field_position_to_gui_position(forward_position);
                new_texture.get()->draw_line(position.x() - 1, position.y() - 1, forward_position.x() - 1, forward_position.y() - 1, scls::Color(255, 0, 255), 2);
            }
        }

        // Create the magnets
        for(int i = 0;i<static_cast<int>(a_magnets.size());i++) {
            // Get the needed position
            scls::Vector_3D position = field_position_to_gui_position(a_magnets[i].get()->physic.attached_transform()->position());
            if(show_magnetic_field()) {
                // Create the magnetical field
                double force_field = std::abs(a_magnets[i].get()->charge * 10e7);
                __needed_angle = 0;
                while(__needed_angle > SCLS_PI) {__needed_angle -= SCLS_PI * 2;}
                while(__needed_angle < -SCLS_PI) {__needed_angle += SCLS_PI * 2;}
                new_texture.get()->fill_circle_gradient(position.x(), position.y(), force_field, scls::Color(0, 255, 0), fill_circle_gradient_magnetic_field);
            }
            // Draw the magnet
            new_texture.get()->paste(a_magnets[i].get()->texture.get(), position.x() - a_magnets[i].get()->texture.get()->width() / 2.0, position.y() - a_magnets[i].get()->texture.get()->height() / 2.0);
        }

        texture()->set_image(new_texture);
    }

    // Field conversions
    scls::Vector_3D Electromagnetism_Field::field_position_to_gui_position(scls::Vector_3D position) {
        scls::Vector_3D to_return;
        to_return.set_x(width_in_pixel() / 4 + (position.x() - a_middle.x()) * a_pixels_by_unit_width);
        to_return.set_y(height_in_pixel() / 4 + ((-position.y()) - a_middle.y()) * a_pixels_by_unit_height);
        return to_return;
    }

    // Updates the objects in the field
    void Electromagnetism_Field::update_field() {
        // Update the objects
        for(int i = 0;i<static_cast<int>(a_objects.size());i++) {
            // Get the needed movement
            scls::Vector_3D acceleration;
            for(int j = 0;j<static_cast<int>(a_objects.size());j++) {
                if(i != j) {
                    // Get the needed acceleration
                    scls::Vector_3D current_acceleration = a_objects[i].get()->vector_to(a_objects[j].get()) * a_objects[i].get()->force_field_produced(a_objects[j].get());
                    if(scls::sign(a_objects[i].get()->charge()) != scls::sign(a_objects[j].get()->charge())){current_acceleration = current_acceleration * -1;}
                    acceleration += current_acceleration;
                }
            } a_objects[i].get()->set_acceleration(acceleration / a_objects[i].get()->mass());
        }
        // Simulate the physic in the object
        for(int i = 0;i<static_cast<int>(a_objects.size());i++) {
            a_objects[i].get()->simulate_physic(window_struct().delta_time());
        }
    }
}
