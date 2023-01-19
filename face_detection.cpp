#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Load the cascades
    CascadeClassifier face_cascade, eyes_cascade, mouth_cascade;
    face_cascade.load("path/to/haarcascade_frontalface_alt.xml");
    eyes_cascade.load("path/to/haarcascade_eye.xml");
    mouth_cascade.load("path/to/haarcascade_mcs_mouth.xml");

    // Open the video stream
    VideoCapture cap(0);
    if (!cap.isOpened())
        return -1;

    Mat frame;
    while (cap.read(frame))
    {
        // Convert to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));

        // Draw rectangles around the faces
        for (auto face : faces)
        {
            rectangle(frame, face, Scalar(255, 0, 0), 2);

            // Crop the face region
            Mat faceROI = gray(face);

            // Detect eyes
            vector<Rect> eyes;
            eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 3, 0, Size(30, 30));

            // Draw rectangles around the eyes
            for (auto eye : eyes)
            {
                Point eye_center(face.x + eye.x + eye.width / 2, face.y + eye.y + eye.height / 2);
                rectangle(frame, eye + eye_center, Scalar(0, 255, 0), 2);
            }

            // Detect mouth
            vector<Rect> mouths;
            mouth_cascade.detectMultiScale(faceROI, mouths, 1.1, 3, 0, Size(30, 30));

            // Draw rectangles around the mouth
            for (auto mouth : mouths)
            {
                Point mouth_center(face.x + mouth.x + mouth.width / 2, face.y + mouth.y + mouth.height / 2);
                rectangle(frame, mouth + mouth_center, Scalar(0, 0, 255), 2);
            }
        }

        // Show the result
        imshow("Tracking", frame);

        // Exit if the user presses 'q'
        if (waitKey(1) == 'q')
            break;
    }

    return 0;
}
