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
        to_return = __create_loaded_object_from_type_equations(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_field(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_home(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Classic object creation
        return GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type_equations(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "electromagnetism_simulation_equations_body") {
            a_equations_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_equations_page;
        } else if(object_name == "electromagnetism_simulation_equations_context") {
            a_equations_context = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_context;
        } else if(object_name == "electromagnetism_simulation_equations_faraday") {
            a_equations_faraday = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_faraday;
        } else if(object_name == "electromagnetism_simulation_equations_faraday_page_1") {
            a_equations_faraday_page_1 = *parent->new_object<scls::GUI_Object>(object_name);
            return a_equations_faraday_page_1;
        } else if(object_name == "electromagnetism_simulation_equations_faraday_page_1_explaination_1") {
            std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_1_explaination_1 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_faraday_page_1_explaination_1.get()->set_max_width(0);
            return a_equations_faraday_page_1_explaination_1;
        } else if(object_name == "electromagnetism_simulation_equations_faraday_page_1_explaination_2") {
            std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_1_explaination_2 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_faraday_page_1_explaination_2.get()->set_max_width(0);
            return a_equations_faraday_page_1_explaination_2;
        } else if(object_name == "electromagnetism_simulation_equations_gauss") {
            a_equations_gauss = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_1") {
            a_equations_gauss_page_1 = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss_page_1;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_1_explaination_1") {
            std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_1_explaination_1 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_gauss_page_1_explaination_1.get()->set_max_width(0);
            return a_equations_gauss_page_1_explaination_1;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_1_explaination_2") {
            std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_1_explaination_2 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_gauss_page_1_explaination_2.get()->set_max_width(0);
            return a_equations_gauss_page_1_explaination_2;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_1_next") {
            a_equations_gauss_page_1_next = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss_page_1_next;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_2") {
            a_equations_gauss_page_2 = *parent->new_object<scls::GUI_Object>(object_name);
            return a_equations_gauss_page_2;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_2_explaination_1") {
            std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_2_explaination_1 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_gauss_page_2_explaination_1.get()->set_max_width(0);
            return a_equations_gauss_page_2_explaination_1;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_2_explaination_2") {
            std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_2_explaination_1 = *parent->new_object<scls::GUI_Text>(object_name);
            a_equations_gauss_page_2_explaination_1.get()->set_max_width(0);
            return a_equations_gauss_page_2_explaination_1;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_2_next") {
            a_equations_gauss_page_2_next = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss_page_2_next;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_2_previous") {
            a_equations_gauss_page_2_previous = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss_page_2_previous;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_3") {
            a_equations_gauss_page_3 = *parent->new_object<scls::GUI_Object>(object_name);
            return a_equations_gauss_page_3;
        } else if(object_name == "electromagnetism_simulation_equations_gauss_page_3_previous") {
            a_equations_gauss_page_3_previous = *parent->new_object<scls::GUI_Text>(object_name);
            return a_equations_gauss_page_3_previous;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Electromagnetism_Simulation::__create_loaded_object_from_type_field(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "electromagnetism_simulation_field_body") {
            a_field_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_field_page;
        } else if(object_name == "electromagnetism_simulation_field_datas") {
            a_field_datas = *parent->new_object<scls::GUI_Text>(object_name);
            return a_field_datas;
        } else if(object_name == "electromagnetism_simulation_field_faraday") {
            a_field_faraday = *parent->new_object<scls::GUI_Text>(object_name);
            return a_field_faraday;
        } else if(object_name == "electromagnetism_simulation_field_gauss") {
            a_field_gauss = *parent->new_object<scls::GUI_Text>(object_name);
            return a_field_gauss;
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
        if(object_name == "electromagnetism_simulation_navigation") {
            a_navigation = *parent->new_object<scls::GUI_Object>(object_name);
            return a_navigation;
        } else if(object_name == "electromagnetism_simulation_navigation_home_button") {
            a_navigation_home_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_home_button;
        } else if(object_name == "electromagnetism_simulation_navigation_equations_button") {
            a_navigation_equations_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_equations_button;
        } else if(object_name == "electromagnetism_simulation_navigation_field_button") {
            a_navigation_field_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_field_button;
        } else if(object_name == "electromagnetism_simulation_navigation_presentation") {
            a_navigation_presentation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_navigation_presentation_button;
        } else if(object_name == "electromagnetism_simulation_presentation") {
            a_presentation = *parent->new_object<scls::GUI_Text>(object_name);
            return a_presentation;
        } return std::shared_ptr<scls::GUI_Object>();
    }

    //******************
    //
    // Field page
    //
    //******************

    // Loads the objects for the field for Faraday experiment
    void Electromagnetism_Simulation::load_field_faraday() {
        // Set the good settings
        a_field_simulator.get()->set_show_acceleration(true);
        a_field_simulator.get()->set_show_electrical_div(false);
        a_field_simulator.get()->set_show_magnetic_field(true);
        a_field_simulator.get()->set_show_trajectory(false);

        // Create the magnet
        std::shared_ptr<Magnet> current_magnet = a_field_simulator.get()->add_magnet(-3 * std::pow(10, -6), -2.5, 0, 0.1);
        // Create needed charges
        for(int i = 0;i<10;i++) {
            std::shared_ptr<Electrical_Charge> current_charge = a_field_simulator.get()->add_electrical_charge(-std::pow(10, -7), 0, -1.0 + static_cast<double>(i) / 5.0, 0.1);
            current_charge.get()->set_acceleration(scls::Vector_3D(1, 0, 0));
            current_charge.get()->set_fixed(true);
            current_charge.get()->set_velocity(scls::Vector_3D(0, -1, 0));
        }
    }

    // Loads the objects for the field for Gauss theorem
    void Electromagnetism_Simulation::load_field_gauss() {
        // Set the good settings
        a_field_simulator.get()->set_show_acceleration(true);
        a_field_simulator.get()->set_show_electrical_div(false);
        a_field_simulator.get()->set_show_magnetic_field(false);
        a_field_simulator.get()->set_show_trajectory(false);

        // Create two fixed points
        std::shared_ptr<Electrical_Charge> current_charge = a_field_simulator.get()->add_electrical_charge(-std::pow(10, -6), -1, 0, 0.1);
        current_charge.get()->set_fixed(true);
        current_charge = a_field_simulator.get()->add_electrical_charge(-2 * std::pow(10, -6), 1, 0, 0.1);
        current_charge.get()->set_fixed(true);
    }

    // Loads the objects for the field at quantum scale
    void Electromagnetism_Simulation::load_field_quantum() {
        // Set the good settings
        a_field_simulator.get()->set_show_acceleration(true);
        a_field_simulator.get()->set_show_electrical_div(false);
        a_field_simulator.get()->set_show_magnetic_field(true);
        a_field_simulator.get()->set_show_trajectory(true);

        // Loads the random objects
        for(int i = 0;i<20;i++) {
            a_field_simulator.get()->add_random_electrical_charge(std::pow(10, -7), 2 * std::pow(10, -7), -1, 1, -1, 1);
        }
        for(int i = 0;i<1;i++) {
            a_field_simulator.get()->add_random_electrical_charge(-2 * std::pow(10, -6), -std::pow(10, -6), -1, 1, -1, 1);
        } //*/
    }

    // Loads the needed objects for the field
    void Electromagnetism_Simulation::load_field_simulation() {
        // Reset the field
        a_field_simulator.get()->reset();
        // Load the field
        if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM) {load_field_quantum();}
        else if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS) {load_field_gauss();}
        else if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_FARADAY) {load_field_faraday();}
        update_field(false);
    }

    // Loads the objects for the field for Thomson theorem
    void Electromagnetism_Simulation::load_field_thomson() {
        // Set the good settings
        a_field_simulator.get()->set_show_acceleration(true);
        a_field_simulator.get()->set_show_electrical_div(false);
        a_field_simulator.get()->set_show_magnetic_field(false);
        a_field_simulator.get()->set_show_trajectory(false);

        // Create one points
        std::shared_ptr<Electrical_Charge> current_charge = a_field_simulator.get()->add_electrical_charge(-std::pow(10, -6), 0, 0, 0.1);
        current_charge.get()->set_fixed(true);
    }

    // Updates the field in the simulation
    void Electromagnetism_Simulation::update_field(bool update_frame) {
        if(update_frame){a_field_simulator.get()->update_field();}
        a_field_simulator.get()->load_field_texture();

        // Set the data text
        if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM) {
            // Sets the number of particules
            a_field_datas.get()->set_text(std::string("Actuellement ") + std::to_string(a_field_simulator.get()->objects().size()) + std::string(" particules simulées."));
        }
        else if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS) {
            std::string final_text = std::string("");
            std::shared_ptr<Electrical_Charge> p_1 = a_field_simulator.get()->objects()[0];
            std::shared_ptr<Electrical_Charge> p_2 = a_field_simulator.get()->objects()[1];

            // Sets the distance of the two particules
            double distance = p_1.get()->distance(p_2.get());
            final_text = std::string("Deux particules séparées de ") + scls::format_number_to_text(distance, 2) + std::string(" mètres.</br>");
            final_text += std::string("La première particule à une charge de ") + scls::format_number_to_text(std::abs(p_1.get()->charge() * 1000000), 2) + std::string(" micro-coulombs.</br>");
            final_text += std::string("La deuxième particule à une charge de ") + scls::format_number_to_text(std::abs(p_2.get()->charge() * 1000000), 2) + std::string(" micro-coulombs.</br>");
            final_text += std::string("La force entre ces deux particule est de ") + scls::format_number_to_text(std::abs(p_2.get()->force_field_produced(p_1.get()) * 1000), 2) + std::string(" milli-newtons.");

            a_field_datas.get()->set_text(final_text);
        }
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Check the navigation event
    void Electromagnetism_Simulation::check_navigation_events() {
        if(a_navigation_equations_button.get() != 0 && a_navigation_equations_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_equations_page();
        if(a_navigation_field_button.get() != 0 && a_navigation_field_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_field_page();
        if(a_navigation_home_button.get() != 0 && a_navigation_home_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_home_page();
    }

    // Check the equations events
    void Electromagnetism_Simulation::check_equations_events() {
        // Go to the Faraday page 1
        if(a_equations_faraday.get() != 0 && a_equations_faraday.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_faraday_page();}
        // Go to the Gauss page 1
        if(a_equations_gauss.get() != 0 && a_equations_gauss.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_gauss_page();}
        // Go to the Gauss page 2
        if(a_equations_gauss_page_1_next.get() != 0 && a_equations_gauss_page_1_next.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_gauss_page_2();}
        // Go to the Gauss page 1 from page 2
        if(a_equations_gauss_page_2_previous.get() != 0 && a_equations_gauss_page_2_previous.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_gauss_page();}
        // Go to the Gauss page 3
        if(a_equations_gauss_page_2_next.get() != 0 && a_equations_gauss_page_2_next.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_gauss_page_3();}
        // Go to the Gauss page 2 from page 3
        if(a_equations_gauss_page_3_previous.get() != 0 && a_equations_gauss_page_3_previous.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_equations_gauss_page_2();}
    }

    // Check the field events
    void Electromagnetism_Simulation::check_field_events() {
        // Set the needed simulation
        if(a_field_quantum.get() != 0 && a_field_quantum.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM);
            load_field_simulation();
        } else if(a_field_gauss.get() != 0 && a_field_gauss.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS);
            load_field_simulation();
        } else if(a_field_faraday.get() != 0 && a_field_faraday.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_FARADAY);
            load_field_simulation();
        }

        // Reset the field
        if(window_struct()->key_pressed_during_this_frame("a")) {load_field_simulation();}

        if(current_simulation() == PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS) {
            // Precisely move charges if necessary
            if(window_struct()->key_pressed("z")) {
                std::vector<std::shared_ptr<Electrical_Charge>>& objects = a_field_simulator.get()->objects();
                objects[0].get()->attached_transform()->move_x(window_struct()->delta_time());
                objects[1].get()->attached_transform()->move_x(-window_struct()->delta_time());
            } if(window_struct()->key_pressed("s")) {
                std::vector<std::shared_ptr<Electrical_Charge>>& objects = a_field_simulator.get()->objects();
                objects[0].get()->attached_transform()->move_x(-window_struct()->delta_time());
                objects[1].get()->attached_transform()->move_x(window_struct()->delta_time());
            }
            // Precisely update charges if necessary
            if(window_struct()->key_pressed("e")) {
                std::vector<std::shared_ptr<Electrical_Charge>>& objects = a_field_simulator.get()->objects();
                objects[0].get()->set_charge(objects[0].get()->charge() + window_struct()->delta_time() * (1.0 / 10e5));
            } if(window_struct()->key_pressed("d")) {
                std::vector<std::shared_ptr<Electrical_Charge>>& objects = a_field_simulator.get()->objects();
                objects[0].get()->set_charge(objects[0].get()->charge() - window_struct()->delta_time() * (1.0 / 10e5));
            }

            // Update the field
            update_field();
        } else if(window_struct()->key_pressed("p")) {update_field();}
    }

    // Check the home events
    void Electromagnetism_Simulation::check_home_events() {}

    // Check the presentation events
    void Electromagnetism_Simulation::check_presentation_events() {
        // Go to next page
        if(window_struct()->key_pressed_during_this_frame("e")) {
            if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_START) {
                // Go to Maxwell-gauss theorem page 1
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_1);
                display_equations_gauss_page();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_1) {
                // Go to Maxwell-gauss theorem simulation 1
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_SIMULATION_1);
                set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS);
                load_field_simulation();
                display_field_page();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_SIMULATION_1) {
                // Go to Maxwell-gauss theorem page 2
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_2);
                display_equations_gauss_page_2();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_2) {
                // Go to Maxwell-Gauss theorem page 3
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_3);
                display_equations_gauss_page_3();
            }
        }

        // Go to previous page
        if(window_struct()->key_pressed_during_this_frame("a")) {
            if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_1) {
                // Go to home page
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_START);
                display_home_page();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_SIMULATION_1) {
                // Go to Maxwell-gauss theorem page 1
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_1);
                display_equations_gauss_page();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_2) {
                // Go to Maxwell-gauss theorem page simulation 1
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_SIMULATION_1);
                set_current_simulation(PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS);
                load_field_simulation();
                display_field_page();
            } else if(current_presentation_state() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_3) {
                // Go to Maxwell-Gauss theorem page 2
                set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_2);
                display_equations_gauss_page_2();
            }
        }
    }

    // Update the events
    void Electromagnetism_Simulation::update_event() {
        GUI_Page::update_event();

        // Check the mode
        if(a_navigation_presentation_button.get() != 0 && a_navigation_presentation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){
            if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION){set_presentation_mode();}
            else if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION){set_navigation_mode();}
        }

        // Check the navigation event
        if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION) {check_navigation_events();}
        if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION) {check_presentation_events();}

        // Equations events
        if(current_page() == PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_PAGE) check_equations_events();
        if(current_page() == PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_GAUSS_PAGE) check_equations_events();
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

    // Displays the equations faraday page
    void Electromagnetism_Simulation::display_equations_faraday_page() {
        hide_all();
        if(a_equations_faraday_page_1.get() != 0) a_equations_faraday_page_1.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_FARADAY_PAGE);
    }

    // Displays the equations gauss page
    void Electromagnetism_Simulation::display_equations_gauss_page() {
        hide_all();
        if(a_equations_gauss_page_1.get() != 0) a_equations_gauss_page_1.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_GAUSS_PAGE);
    }

    // Displays the equations gauss page 2
    void Electromagnetism_Simulation::display_equations_gauss_page_2() {
        hide_all();
        if(a_equations_gauss_page_2.get() != 0) a_equations_gauss_page_2.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_GAUSS_PAGE);
    }

    // Displays the equations gauss page 3
    void Electromagnetism_Simulation::display_equations_gauss_page_3() {
        hide_all();
        if(a_equations_gauss_page_3.get() != 0) a_equations_gauss_page_3.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_GAUSS_PAGE);
    }

    // Displays the equations page
    void Electromagnetism_Simulation::display_equations_page() {
        hide_all();
        if(a_equations_page.get() != 0) a_equations_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_PAGE);
    }

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
        if(a_equations_faraday_page_1.get() != 0) a_equations_faraday_page_1.get()->set_visible(false);
        if(a_equations_gauss_page_1.get() != 0) a_equations_gauss_page_1.get()->set_visible(false);
        if(a_equations_gauss_page_2.get() != 0) a_equations_gauss_page_2.get()->set_visible(false);
        if(a_equations_gauss_page_3.get() != 0) a_equations_gauss_page_3.get()->set_visible(false);
        if(a_equations_page.get() != 0) a_equations_page.get()->set_visible(false);
        if(a_field_page.get() != 0) a_field_page.get()->set_visible(false);
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(false);

        if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION) {a_navigation.get()->set_visible(true);a_presentation.get()->set_visible(false);}
        if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION) {a_navigation.get()->set_visible(false);a_presentation.get()->set_visible(true);}

        // Clear the needed part
    }

    // Sets the navigation mode
    void Electromagnetism_Simulation::set_navigation_mode() {
        set_current_mode(PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION);
        display_home_page();
    }

    // Sets the presentation mode
    void Electromagnetism_Simulation::set_presentation_mode() {
        if(current_mode() == PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION){return;}

        set_current_mode(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION);
        set_current_presentation(PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_START);
        display_home_page();
    }
}
