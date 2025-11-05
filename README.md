"# TaxonomicalSearch" 

Welcome to Taxonomical Search! This is made by Group 097, AKA Epic and Awesome DSA Group of DOOM. We hope you enjoyed the video.


Please do this first:

Because of the limitations of gitHub, we were unable to provide the actual taxonomical data from IRMING in the repository. This unfortuantely 
means you must download the data. Please follow these steps:

    1. Go to this website: https://www.irmng.org/export/
    2. Click on the "2025/" link
    3. Click on "IRMNG_genera_DwCA_2025-07-11.zip"
    4. Upon successfully downloading, extract the zip file
    5. Locate "taxon.txt" and drag that file into the "data" folder in the root of this project


Using Taxonomical Search:

Upon running the program, you will be greeted with a menu. To read from data, first read in the data by selecting 1, and then inputting the filename.
Afterwards, you can list out the entries or do the searches through them. We recommend testing our code first with the given, smaller files in the /data folder
in the root of the project. You do not need to put the entire relative path when prompted, just the name of the file. 

We recommend using Menu Option 2 to peruse the smaller test files (found in data/) to find taxon to search using Menu Option 3. However, we do not recommend doing this
for the actual database, for it will take a very long time for it to print the entire database. You may still do so by bypassing the warning the UI will give, but
be prepared to terminate the program if it takes too long. Here are some randomly selected taxonomical entries (paths) in the IRMING database that you can search for 
any componenent of:

    Path to Zimiris, AKA Zimiris:
    Animalia, Arthropoda, Arachnida, Araneae, Prodidomidae, Zimiris
    Path to Tridesmostemon, AKA Tridesmostemon:
    Plantae, Tracheophyta, Magnoliopsida, Ericales, Sapotaceae, Tridesmostemon
    Path to Cepsiclava, AKA Cepsiclava:
    Fungi, Ascomycota, Sordariomycetes, Hypocreales, Clavicipitaceae, Cepsiclava
    Path to Phthanotrochus, AKA Phthanotrochus:
    Chromista, Retaria, Monothalamea, Allogromiida, Phthanotrochidae, Phthanotrochus

    And feel free to test others to keep us honest! 

Menu Option 3 will first prompt the user to input the taxon they are locating. Then, it will ask the user which algorithm they would like to choose. After one is selected,
It will print the path and the amount of time it took for the taxon to be found. Then the menu is printed again. This means the discovered taxon and path will be above 
the menu after searching.

Thank you for using Taxonomical Search.