//******************
//
// pleos_electromagnetism_simulation.h
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
// This file contains the page of the Electromagnetism Simulation plugin.
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

#ifndef PLEOS_ELECTROMAGNETISM_SIMULATION
#define PLEOS_ELECTROMAGNETISM_SIMULATION

// Include PLEOS Libs
#include "pleos_electromagnetism_simulation_field.h"

// Possibles pages
#define PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE 0
#define PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD_PAGE 1

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Electromagnetism_Simulation : public scls::GUI_Page {
        // Class representating the electromagnetism simulation page for PLEOS
    public:

        // Electromagnetism_Simulation constructor
        Electromagnetism_Simulation(scls::_Window_Advanced_Struct* window_struct, std::string name);
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_field(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Check the events
        //
        //******************

        // Check the field events
        void check_field_events();
        // Check the home events
        void check_home_events();
        // Check the navigation events
        void check_navigation_events();
        // Update the events
        void update_event();

        // Function called after an XML loading
        virtual void after_xml_loading() {scls::GUI_Page::after_xml_loading();display_home_page();};

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the field page
        void display_field_page();
        // Displays the home page
        void display_home_page();
        // Hides all the pages
        void hide_all();

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE;
        } a_current_state;

        //******************
        //
        // GUI stuff
        //
        //******************

        // Navigation button
        std::shared_ptr<scls::GUI_Text> a_navigation_home_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_field_button;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_home_page;

        // Field page
        std::shared_ptr<scls::GUI_Object> a_field_page;
        std::shared_ptr<Electromagnetism_Field> a_field_simulator;
    };

    class __Temp_Pleos_Window : public scls::Window {
        // Temporary used window by PLEOS
    public :
        // __Temp_Pleos_Window constructor
        __Temp_Pleos_Window(unsigned int w, unsigned int h, std::string path) : scls::Window(w, h, path) { set_window_title("PLEOS - Solveur algébrique"); }

        // Create an object in the window
        std::shared_ptr<scls::Object> __create_loaded_object_from_type(std::string object_name, std::string object_type) {
            if(object_name == "electromagnetism_simulation") {
                std::shared_ptr<Electromagnetism_Simulation> hub = *new_page_2d<Electromagnetism_Simulation>(object_name);

                // Return the good object
                std::shared_ptr<scls::Object> to_return = hub;
                return to_return;
            } return scls::Window::__create_loaded_object_from_type(object_name, object_type);
        }
    };
}

#endif // PLEOS_ELECTROMAGNETISM_SIMULATION