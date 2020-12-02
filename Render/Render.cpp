#include "pch.h"

HWND hwndAC_Client;
HDC hdcAC_client;
HBRUSH Brush;
HFONT Font;
COLORREF TextCOLOR;
COLORREF TextCOLORRED;

bool Render::WorldToScreen(Vec3 posS, Vec2& screen, float matrix[16], int wWidth, int wHeight)
{
	Vec4 clipCoords;
	clipCoords.x = posS.x * matrix[0] + posS.y * matrix[4] + posS.z * matrix[8] + matrix[12];
	clipCoords.y = posS.x * matrix[1] + posS.y * matrix[5] + posS.z * matrix[9] + matrix[13];
	clipCoords.z = posS.x * matrix[2] + posS.y * matrix[6] + posS.z * matrix[10] + matrix[14];
	clipCoords.w = posS.x * matrix[3] + posS.y * matrix[7] + posS.z * matrix[11] + matrix[15];
	if (clipCoords.w < 0.1f)
		return false;
	Vec3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;
	screen.x = (wWidth / 2 * NDC.x) + (NDC.x + wWidth / 2);
	screen.y = -(wHeight / 2 * NDC.y) + (NDC.y + wHeight / 2);
	return true;

}

void Render::DrawBorderBox(int x, int y, int w, int h, int thickness)
{

	DrawFilledRect(x, y, w, thickness);
	DrawFilledRect(x, y, thickness, h);
	DrawFilledRect((x + w), y, thickness, h);
	DrawFilledRect(x, y + h, w + thickness, thickness);
}

void Render::DrawString(int x, int y, COLORREF color, const char* text)
{
	SetTextAlign(hdcAC_client, TA_CENTER | TA_NOUPDATECP);
	SetBkColor(hdcAC_client, RGB(0, 0, 0));
	SetBkMode(hdcAC_client, TRANSPARENT);
	SetTextColor(hdcAC_client, color);
	SelectObject(hdcAC_client, Font);
	TextOutA(hdcAC_client, x, y, text, strlen(text));
	DeleteObject(Font);
}

void Render::DrawFilledRect(int x, int y, int w, int h)
{
	RECT rect = { x, y, x + w, y + h };
	FillRect(hdcAC_client, &rect, Brush);
}

void Render::DrawLine(int targetX, int targetY)
{
	MoveToEx(hdcAC_client, 960, 1080, NULL);
	LineTo(hdcAC_client, targetX, targetY);
}
