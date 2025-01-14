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

// Possibles modes
#define PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION 0
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION 1
// Possibles pages
#define PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE 0
#define PLEOS_ELECTROMAGNETISM_SIMULATION_FIELD_PAGE 1
#define PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_PAGE 2
#define PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_GAUSS_PAGE 3
#define PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_FARADAY_PAGE 4
#define PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_THOMSON_PAGE 5
#define PLEOS_ELECTROMAGNETISM_SIMULATION_TECHNIQUES_PAGE 6
#define PLEOS_ELECTROMAGNETISM_SIMULATION_TECHNIQUES_CURRENT_PAGE 7
#define PLEOS_ELECTROMAGNETISM_SIMULATION_TECHNIQUES_MOTOR_PAGE 8
#define PLEOS_ELECTROMAGNETISM_SIMULATION_SOCIAL_PAGE 9
#define PLEOS_ELECTROMAGNETISM_SIMULATION_EQUATIONS_CONTEXT_PAGE 10
// Possible presentation states
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_START 0
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_CONTEXT 1
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_1 100
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_SIMULATION_1 101
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_2 102
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_GAUSS_THEOREM_3 103
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_FARADAY_THEOREM_1 200
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_FARADAY_THEOREM_SIMULATION_1 201
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_FARADAY_THEOREM_2 202
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_FARADAY_THEOREM_3 203
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_MAXWELL_THOMSON_THEOREM_1 300
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_1 400
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_CURRENT_1 500
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_CURRENT_2 501
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_CURRENT_3 502
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_MOTOR_1 600
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_TECHNIQUE_MOTOR_2 601
#define PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_SOCIAL 700
// Possibles simulation
#define PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM 0
#define PLEOS_ELECTROMAGNETISM_SIMULATION_GAUSS 1
#define PLEOS_ELECTROMAGNETISM_SIMULATION_FARADAY 2

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Electromagnetism_Simulation : public scls::GUI_Page {
        // Class representating the electromagnetism simulation page for PLEOS
    public:

        // Electromagnetism_Simulation constructor
        Electromagnetism_Simulation(scls::_Window_Advanced_Struct* window_struct, std::string name);
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_equations(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_field(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_social(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_techniques(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Field page
        //
        //******************

        // Loads the objects for the field for Faraday experiment
        void load_field_faraday();
        // Loads the objects for the field for Gauss theorem
        void load_field_gauss();
        // Loads the objects for the field at quantum scale
        void load_field_quantum();
        // Loads the needed objects for the field
        void load_field_simulation();
        // Loads the objects for the field for Thomson theorem
        void load_field_thomson();
        // Unloads the objects in the field
        inline void unload_field_objects() {a_field_objects.get()->reset();};
        // Updates the field in the simulation
        void update_field(bool update_frame = true);

        //******************
        //
        // Check the events
        //
        //******************

        // Check the equations events
        void check_equations_events();
        // Check the field events
        void check_field_events();
        // Check the home events
        void check_home_events();
        // Check the navigation events
        void check_navigation_events();
        // Check the presentation events
        void check_presentation_events();
        // Check the social events
        void check_social_events();
        // Check the techniques events
        void check_techniques_events();
        // Update the events
        void update_event();

        // Function called after an XML loading
        virtual void after_xml_loading() {scls::GUI_Page::after_xml_loading();display_home_page();load_field_simulation();};

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the equations context page
        void display_equations_context_page();
        // Displays the equations faraday page
        void display_equations_faraday_page();
        void display_equations_faraday_page_2();
        void display_equations_faraday_page_3();
        // Displays the equations gauss page
        void display_equations_gauss_page();
        void display_equations_gauss_page_2();
        void display_equations_gauss_page_3();
        // Displays the equations page
        void display_equations_page();
        // Displays the equations thomson page
        void display_equations_thomson_page();
        // Displays the field page
        void display_field_page();
        // Displays the home page
        void display_home_page();
        // Displays the social page
        void display_social_page();
        // Displays the techniques page
        void display_techniques_page();
        // Displays the techniques current page
        void display_techniques_current_page();
        void display_techniques_current_page_2();
        void display_techniques_current_page_3();
        // Displays the techniques motor page
        void display_techniques_motor_page();
        void display_techniques_motor_page_2();
        // Hides all the pages
        void hide_all();
        // Sets the navigation mode
        void set_navigation_mode();
        // Sets the presentation mode
        void set_presentation_mode();

        // Returns / resets the current page
        inline unsigned char current_mode() const {return a_current_state.current_mode;};
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline unsigned short current_presentation_state() const {return a_current_state.current_presentation_state;};
        inline unsigned short current_simulation() const {return a_current_state.current_simulation;};
        inline void set_current_mode(unsigned char new_mode) {a_current_state.current_mode = new_mode;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};
        inline void set_current_presentation(unsigned short new_presentation_state) {a_current_state.current_presentation_state = new_presentation_state;};
        inline void set_current_simulation(unsigned short new_simulation) {a_current_state.current_simulation = new_simulation;};

    private:

        // Current state of the page
        struct {
            // Current mode
            unsigned char current_mode = PLEOS_ELECTROMAGNETISM_SIMULATION_NAVIGATION;
            // Current page
            unsigned short current_page = PLEOS_ELECTROMAGNETISM_SIMULATION_HOME_PAGE;

            // Current state of presentation
            unsigned short current_presentation_state = PLEOS_ELECTROMAGNETISM_SIMULATION_PRESENTATION_START;
            // Current simulation
            unsigned short current_simulation = PLEOS_ELECTROMAGNETISM_SIMULATION_QUANTUM;
        } a_current_state;

        //******************
        //
        // GUI stuff
        //
        //******************

        // Navigation
        std::shared_ptr<scls::GUI_Text> a_navigation_presentation_button;
        std::shared_ptr<scls::GUI_Object> a_navigation;
        std::shared_ptr<scls::GUI_Object> a_presentation;
        // Navigation buttons
        std::shared_ptr<scls::GUI_Text> a_navigation_home_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_equations_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_field_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_social_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_techniques_button;
        // Presentation buttons
        std::shared_ptr<scls::GUI_Text> a_presentation_maxwell_gauss_button;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_equations_page;
        std::shared_ptr<scls::GUI_Object> a_field_page;
        std::shared_ptr<scls::GUI_Object> a_home_page;
        std::shared_ptr<scls::GUI_Object> a_social_page;
        std::shared_ptr<scls::GUI_Object> a_techniques_page;

        // Equations page
        std::shared_ptr<scls::GUI_Text> a_equations_context;
        std::shared_ptr<scls::GUI_Object> a_equations_faraday;
        std::shared_ptr<scls::GUI_Object> a_equations_gauss;
        std::shared_ptr<scls::GUI_Object> a_equations_thomson;
        // Context page
        std::shared_ptr<scls::GUI_Object> a_equations_context_page;
        // Faraday page
        std::shared_ptr<scls::GUI_Object> a_equations_faraday_page_1;
        std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_1_next;
        std::shared_ptr<scls::GUI_Object> a_equations_faraday_page_2;
        std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_2_next;
        std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_2_previous;
        std::shared_ptr<scls::GUI_Object> a_equations_faraday_page_3;
        std::shared_ptr<scls::GUI_Text> a_equations_faraday_page_3_previous;
        // Gauss page
        std::shared_ptr<scls::GUI_Object> a_equations_gauss_page_1;
        std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_1_next;
        std::shared_ptr<scls::GUI_Object> a_equations_gauss_page_2;
        std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_2_next;
        std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_2_previous;
        std::shared_ptr<scls::GUI_Object> a_equations_gauss_page_3;
        std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_3_next;
        std::shared_ptr<scls::GUI_Text> a_equations_gauss_page_3_previous;
        // Thompson page
        std::shared_ptr<scls::GUI_Object> a_equations_thomson_page_1;

        // Field page
        std::shared_ptr<scls::GUI_Text> a_field_datas;
        std::shared_ptr<scls::GUI_Text> a_field_faraday;
        std::shared_ptr<scls::GUI_Text> a_field_gauss;
        std::shared_ptr<scls::GUI_Scroller> a_field_objects;
        std::shared_ptr<scls::GUI_Text> a_field_quantum;
        std::shared_ptr<Electromagnetism_Field> a_field_simulator;

        // Social page


        // Techniques page
        std::shared_ptr<scls::GUI_Text> a_techniques_current;
        std::shared_ptr<scls::GUI_Text> a_techniques_motor;
        // Current page
        std::shared_ptr<scls::GUI_Object> a_techniques_current_page_1;
        std::shared_ptr<scls::GUI_Text> a_techniques_current_page_1_next;
        std::shared_ptr<scls::GUI_Object> a_techniques_current_page_2;
        std::shared_ptr<scls::GUI_Text> a_techniques_current_page_2_previous;
        std::shared_ptr<scls::GUI_Text> a_techniques_current_page_2_next;
        std::shared_ptr<scls::GUI_Object> a_techniques_current_page_3;
        std::shared_ptr<scls::GUI_Text> a_techniques_current_page_3_previous;
        // Motor page
        std::shared_ptr<scls::GUI_Object> a_techniques_motor_page_1;
        std::shared_ptr<scls::GUI_Text> a_techniques_motor_page_1_next;
        std::shared_ptr<scls::GUI_Object> a_techniques_motor_page_2;
        std::shared_ptr<scls::GUI_Text> a_techniques_motor_page_2_previous;
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
