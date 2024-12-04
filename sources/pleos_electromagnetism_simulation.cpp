//******************
//
// pleos_electromagnetism_simulation.cpp
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
// This file contains the source code of pleos_electromagnetism_simulation.h.
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

// Include pleos_electromagnetism_simulation.h
#include "../headers/pleos_electromagnetism_simulation.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Electromagnetism_Simulation constructor
    Electromagnetism_Simulation::Electromagnetism_Simulation(scls::_Window_Advanced_Struct* window_struct, std::string name) : scls::GUI_Page(window_struct, name) {}

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        std::shared_ptr<scls::GUI_Object> to_return;

        // Check navigation
        to_return = __create_loaded_object_from_type_navigation(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Check page by page
        to_return = __create_loaded_object_from_type_field(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_home(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Classic object creation
        return GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type_field(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "electromagnetism_simulation_field_body") {
            a_field_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_field_page;
        } else if(object_name == "electromagnetism_simulation_field_objects") {
            a_field_objects = *parent->new_object<scls::GUI_Scroller>(object_name);
            return a_field_objects;
        } else if(object_name == "electromagnetism_simulation_field_quantum") {
            a_field_quantum = *parent->new_object<scls::GUI_Text>(object_name);
            return a_field_quantum;
        } else if(object_name == "electromagnetism_simulation_field_simulator") {
            a_field_simulator = *parent->new_object<Electromagnetism_Field>(object_name);
            return a_field_simulator;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "electromagnetism_simulation_home_body") {
            a_home_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_home_page;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "electromagnetism_simulation_navigation_home_button") {
            a_navigation_home_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_home_button;
        } else if(object_name == "electromagnetism_simulation_navigation_field_button") {
            a_navigation_field_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_field_button;
        } return std::shared_ptr<scls::GUI_Object>();
    }

    //******************
    //
    // Field page
    //
    //******************

    // Loads the objects for the field at quantum scale
    void Electromagnetism_Simulation::load_field_quantum() {
        // Reset the field
        a_field_simulator.get()->reset();

        // Loads the random objects
        for(int i = 0;i<5;i++) {
            a_field_simulator.get()->add_random_electrical_charge(std::pow(10, -7), 2 * std::pow(10, -7), -2, 2, -1, 1);
        } a_field_simulator.get()->add_random_electrical_charge(-2 * std::pow(10, -6), -std::pow(10, -6), -2, 2, -1, 1);
        a_field_simulator.get()->load_field_texture();
    }

    // Loads the needed objects for the field
    void Electromagnetism_Simulation::load_field_simulation() {
        if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM) {load_field_quantum();}
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Check the navigation event
    void Electromagnetism_Simulation::check_navigation_events() {
        if(a_navigation_field_button.get() != 0 && a_navigation_field_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_field_page();
        if(a_navigation_home_button.get() != 0 && a_navigation_home_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_home_page();
    }

    // Check the field events
    void Electromagnetism_Simulation::check_field_events() {
        // Set the needed simulation
        if(a_field_quantum.get() != 0 && a_field_quantum.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM);
            load_field_simulation();
        }

        // Reset the field
        if(window_struct()->key_pressed_during_this_frame("a")) {load_field_simulation();}

        // Update the field
        if(window_struct()->key_pressed("p")) {
            a_field_simulator.get()->update_field();
            a_field_simulator.get()->load_field_texture();
        }
    }

    // Check the home events
    void Electromagnetism_Simulation::check_home_events() {}

    // Update the events
    void Electromagnetism_Simulation::update_event() {
        GUI_Page::update_event();

        // Check the navigation event
        check_navigation_events();

        // Field events
        if(current_page() == PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD_PAGE) check_field_events();
        // Home events
        if(current_page() == PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE) check_home_events();
    }

    //******************
    //
    // Handle the pages
    //
    //******************

    // Displays the field page
    void Electromagnetism_Simulation::display_field_page() {
        hide_all();
        if(a_field_page.get() != 0) a_field_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD_PAGE);
    }

    // Displays the home page
    void Electromagnetism_Simulation::display_home_page() {
        hide_all();
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE);
    }

    // Hides all the pages
    void Electromagnetism_Simulation::hide_all() {
        if(a_field_page.get() != 0) a_field_page.get()->set_visible(false);
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(false);

        // Clear the needed part
    }
}
